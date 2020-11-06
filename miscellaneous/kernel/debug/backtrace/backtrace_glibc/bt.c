/*
 *
    glibc code for backtrace and backtrace_symbols_fd
    https://github.com/lattera/glibc/blob/master/debug/backtrace.c 
    https://github.com/lattera/glibc/blob/master/debug/backtracesymsfd.c
    
    gcc -g bt.c
    ./a.out 
    Error: signal 11:
    ./a.out[0x804853c]
    [0xb7f3fd10]
    ./a.out[0x80485b2]
    ./a.out[0x80485bf]
    ./a.out[0x80485e3]
    /lib/i386-linux-gnu/libc.so.6(__libc_start_main+0xf7)[0xb7d86637]

    -- extract code location
    addr2line 0x804853c -e a.out -f

 */

#include <stdio.h>
#include <execinfo.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>


void handler(int sig) {
  void *array[10];
  size_t size;

  // get void*'s for all entries on the stack
  size = backtrace(array, 10);

  // print out all the frames to stderr
  fprintf(stderr, "Error: signal %d:\n", sig);
  backtrace_symbols_fd(array, size, STDERR_FILENO);
  exit(1);
}

void baz() {
 int *foo = (int*)-1; // make a bad pointer
  printf("%d\n", *foo);       // causes segfault
}

void bar() { baz(); }
void foo() { bar(); }


int main(int argc, char **argv) {
  signal(SIGSEGV, handler);   // install our handler
  foo(); // this will call foo, bar, and baz.  baz segfaults.
}
