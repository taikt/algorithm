/*
 * gcc -g -o unwinded unwinded_pr.c
 *
 */

#include <stdio.h>


void loo() {
    while (1);
}
void foo() {
    loo();
}

void bar() {
    foo();
}

int main() {
    bar();
    return 0;
}
