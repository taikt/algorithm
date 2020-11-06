/*
http://www.brendangregg.com/blog/2016-08-09/gdb-example-ncurses.html

ulimit -c unlimited
echo "/home/tai/work/tmas/coredump/t2/core.%e.%p" > /proc/sys/kernel/core_pattern ==> set coredump_file as core.%e.%p at current path

--debug coredump file with gdb
gdb a.out coredump_file
bt ==> to backtrack
*/

#include <stdio.h>
void foo()
{
    int *ptr = 0;
    *ptr = 19; // crashed point
    /*
    while (1) {
    }
    */
    printf("ok\n");
}

int main()
{
    foo();
    return 0;
}
