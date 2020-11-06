#include <stdio.h>
#include "../lib1/ctest1.h"

void ctest3(int *i)
{
   printf("ctest3: ctest2 lib is called\n");
   int a;
   //*i=6;
   ctest1(&a);
   *i = a;
}
