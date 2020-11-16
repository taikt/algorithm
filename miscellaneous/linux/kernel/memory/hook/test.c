#include <stdio.h>

int main() {
    
    int *a = (int*) malloc(4); 
    free(a);    

    return 0;
}
