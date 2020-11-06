#include "stdio.h"
#include "../lib3/cpptest1.h"

void fun3_lib(int *i)
{
   printf("fun3_lib: cpptest2 lib is called\n");
   int a=3;
   fun1_lib(&a);
   *i = a;
}
