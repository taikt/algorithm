#include <stdio.h>

int main() {
    printf("start process\n");
    sleep(1);
    exit(-1);
    while (sleep(20)) 
    {
    };
    
    printf("ok exit");
    return 0;
}
