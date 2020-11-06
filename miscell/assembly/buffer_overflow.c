#include <string.h>
#include <stdio.h>
void function2() {
    printf("Execution flow changed\n");
}

void function1(char *str){
    char buffer[5];
    strcpy(buffer, str);
}

void main(int argc, char *argv[])
{
    function1(argv[1]);
    printf("Executed normally\n");
    printf("ok\n");
}
