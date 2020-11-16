/*
 *
    sudo apt-get install libunwind-dev
    gcc -o libunwind_backtrace -Wall -g libunwind_backtrace.c -lunwind
    https://eli.thegreenplace.net/2015/programmatic-access-to-the-call-stack-in-c/

    0x804875b: (loo+0xb)
    0x8048768: (foo+0xb)
    0x8048775: (bar+0xb)
    0x8048782: (main+0xb)
    0xb7d65637: (__libc_start_main+0xf7)
    0x80485a1: (_start+0x21)

    -- extract source location.
    addr2line -e libunwind_backtrace 0x804875b -f
    or gdb libunwind_backtrace
    list *(main+0xb)

Ref:
http://collab.lge.com/main/pages/viewpage.action?pageId=568551272
http://collab.lge.com/main/pages/viewpage.action?pageId=727814109
*/

#define UNW_LOCAL_ONLY
#include <libunwind.h>
#include <stdio.h>

// Call this function to get a backtrace.
void backtrace() {
    unw_cursor_t cursor;
    unw_context_t context;

    // Initialize cursor to current frame for local unwinding.
    unw_getcontext(&context);
    unw_init_local(&cursor, &context);

    // Unwind frames one by one, going up the frame stack.


    while (unw_step(&cursor) > 0) {
        unw_word_t offset, pc;
        unw_get_reg(&cursor, UNW_REG_IP, &pc);
    
        if (pc == 0) {
            break;
        }

        printf("0x%lx:", pc);

        char sym[256];
        if (unw_get_proc_name(&cursor, sym, sizeof(sym), &offset) == 0) {
            printf(" (%s+0x%lx)\n", sym, offset);
        } else {
            printf(" -- error: unable to obtain symbol name for this frame\n");
        }
   }
}

void loo() {
      backtrace(); // <-------- backtrace here!
}
void foo() {
    loo();
}

void bar() {
      foo();
}

int main(int argc, char **argv) {
      bar();
      
      return 0;
}
