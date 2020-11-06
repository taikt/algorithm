#include <stdio.h>
#include <h1.h>

#include "lib/ex2/lib3/cpptest1.h"
#include "lib/ex2/lib4/cpptest2.h"

// need extern if using c lib in cpp code
#ifdef __cplusplus
extern "C"{
#endif 
#include "lib/ex2/lib1/ctest1.h"
#include "lib/ex2/lib2/ctest2.h"
#ifdef __cplusplus
}
#endif


int main() {
    
    int x=1;
    printf("hello world\n");
    func1(2);
    func2(3);

    //ctest1(&x);
    //printf("%d\n",x);
    
    //fun3_lib(&x);
    //printf("%d\n",x);
    
    fun1_lib(&x);
    printf("%d\n",x);
    
    //ctest3(&x);
    //printf("%d\n",x);
 
    return 0;
}
