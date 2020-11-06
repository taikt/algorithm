#include <stdio.h>

extern "C" {
    void ctest1(int *);
}

void fun1_lib(int *);

int main() {
    int x;
    printf("hello world\n");
    //printA("testing..");
    ctest1(&x);
    printf("%d\n",x);
    
    fun1_lib(&x);
    printf("%d\n",x);

    return 0;
}
