/*  Hook memory allocation by LD_PRELOAD and ldsym
 *  
 *  purpose: to debug memory allocation
 *
 *  build libmem.so
 *  gcc malloc_overwrite.c -fPIC -shared -o libmem.so -ldl
 *  cp libmem.so /usr/bin/.
 *  gcc -g test.c => a.out
 *  LD_PRELOAD=libmem.so ./a.out
 *
 *  TODO: hook by _malloc_hook by glibc
 *  Ref:
 *  https://elinux.org/images/b/b5/Elc2013_Kobayashi.pdf
 *  https://stackoverflow.com/questions/6083337/overriding-malloc-using-the-ld-preload-mechanism
 *  https://www.gnu.org/savannah-checkouts/gnu/libc/manual/html_node/Hooks-for-Malloc.html  
 *
 * */
#define _GNU_SOURCE

#include <stdio.h>
#include <dlfcn.h>

static void* (*real_malloc)(size_t)=NULL;
static void (*real_free)(void *ptr)=NULL;

static void mtrace_init(void)
{
    real_malloc = dlsym(RTLD_NEXT, "malloc");
    real_free = dlsym(RTLD_NEXT, "free");
    if ((NULL == real_malloc) || (NULL == real_free)) {
        fprintf(stderr, "Error in `dlsym`: %s\n", dlerror());
    }
}

void free(void *ptr) {
     fprintf(stderr,"free pointer %p\n", ptr);
     
     if (real_free == NULL)
         mtrace_init();

     real_free(ptr);   
}

void *malloc(size_t size)
{
    if(real_malloc==NULL) {
        fprintf(stderr,"init mtrace\n");
        //printf("init mtrace\n");
        // Note: not use printf, because printf uses malloc and free from glibc.
        mtrace_init();
    }

    void *p = NULL;
    fprintf(stderr, "malloc(%d) = ", size);
    p = real_malloc(size);
    fprintf(stderr, "%p\n", p);
    
    return p;
}

#if 0
int main() {
    int *a = (int*) malloc(4*sizeof(int));
    fprintf(stderr,"address of a=%p\n",a);
    if (a != NULL)    
        free(a);

    return 0;
}
#endif
