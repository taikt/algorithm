/*
 *
 *  TODO: FIX compile
 *
 *
 * */


#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/string.h>
#include<linux/vmalloc.h>
#include<linux/mm.h>
#include<linux/init.h>
#include<linux/proc_fs.h>
#include<linux/sched.h>
#include<linux/uaccess.h>
#include<linux/fs.h>
#include<linux/seq_file.h>
#include<linux/slab.h>

static void get_pgtable_macro(void)
    {
        printk("PAGE_OFFSET = 0x%lx\n", PAGE_OFFSET);
        printk("PGDIR_SHIFT = %d\n", PGDIR_SHIFT);
        printk("PUD_SHIFT = %d\n", PUD_SHIFT);
        printk("PMD_SHIFT = %d\n", PMD_SHIFT);
        printk("PAGE_SHIFT = %d\n", PAGE_SHIFT);

        printk("PTRS_PER_PGD = %d\n", PTRS_PER_PGD);
        printk("PTRS_PER_PUD = %d\n", PTRS_PER_PUD);
        printk("PTRS_PER_PMD = %d\n", PTRS_PER_PMD);
        printk("PTRS_PER_PTE = %d\n", PTRS_PER_PTE);

        printk("PAGE_MASK = 0x%lx\n", PAGE_MASK);
    }

    static unsigned long vaddr2paddr(unsigned long vaddr)
    {
        pgd_t *pgd;
        pud_t *pud;
        pmd_t *pmd;
        pte_t *pte;
        unsigned long paddr = 0;
            unsigned long page_addr = 0;
        unsigned long page_offset = 0;

        pgd = pgd_offset(current->mm, vaddr);
        printk("pgd_val = 0x%lx\n", pgd_val(*pgd));
        printk("pgd_index = %lu\n", pgd_index(vaddr));
        if (pgd_none(*pgd)) {
            printk("not mapped in pgd\n");
            return -1;
        }

        pud = pud_offset(pgd, vaddr);
        printk("pud_val = 0x%lx\n", pud_val(*pud));
        if (pud_none(*pud)) {
            printk("not mapped in pud\n");
            return -1;
        }

        pmd = pmd_offset(pud, vaddr);
        printk("pmd_val = 0x%lx\n", pmd_val(*pmd));
        printk("pmd_index = %lu\n", pmd_index(vaddr));
        if (pmd_none(*pmd)) {
            printk("not mapped in pmd\n");
            return -1;
        }

        pte = pte_offset_kernel(pmd, vaddr);
        printk("pte_val = 0x%lx\n", pte_val(*pte));
        printk("pte_index = %lu\n", pte_index(vaddr));
        if (pte_none(*pte)) {
            printk("not mapped in pte\n");
            return -1;
        }

        /* Page frame physical address mechanism | offset */
        page_addr = pte_val(*pte) & PAGE_MASK;
        page_offset = vaddr & ~PAGE_MASK;
        paddr = page_addr | page_offset;
        printk("page_addr = %lx, page_offset = %lx\n", page_addr, page_offset);
            printk("vaddr = %lx, paddr = %lx\n", vaddr, paddr);

        return paddr;
    }

    static int __init v2p_init(void)
    {
        unsigned long vaddr = 0;

        printk("vaddr to paddr module is running..\n");
        get_pgtable_macro();
        printk("\n");

        vaddr = (unsigned long)vmalloc(1000 * sizeof(char));
        if (vaddr == 0) {
            printk("vmalloc failed..\n");
            return 0;
        }
        printk("vmalloc_vaddr=0x%lx\n", vaddr);
        vaddr2paddr(vaddr);

        printk("\n\n");
        vaddr = __get_free_page(GFP_KERNEL);
        if (vaddr == 0) {
            printk("__get_free_page failed..\n");
            return 0;
        }
        printk("get_page_vaddr=0x%lx\n", vaddr);
        vaddr2paddr(vaddr);

        return 0;
    }

    static void __exit v2p_exit(void)
    {
        printk("vaddr to paddr module is leaving..\n");
            vfree((void *)vaddr);
            free_page(vaddr);
    }
