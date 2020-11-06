#include <stdio.h>
#include "cpptest1.h"

void fun1_lib(int *i)
{
   printf("func1_lib: cpptest1 lib is called\n");
   int a=9;
   ctest1(&a);
   *i = a;
}
