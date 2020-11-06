#include <stdio.h>

int printF() {
    
    int a = 1/0;
    int* b;
    printf("printfF_0\n");
    *b = 2;
    free(b);
    free(b);
    printf("printfF_1\n");

    return 0;
}

void printF2() {
    printf("printfF2\n");
    printF();
}

void printF1() {
    printf("printfF1\n");
    printF2();

}


int main() {
    printF1();

    return 0;
}

