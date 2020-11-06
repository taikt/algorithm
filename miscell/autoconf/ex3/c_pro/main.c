#include <stdio.h>

void ctest(int *);

int main() {
    int x;
    printf("hello world\n");
    ctest1(&x);
    printf("%d\n",x);

    return 0;
}
