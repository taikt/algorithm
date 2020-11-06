// must use extern c for including a C shared lib

#if 0
#ifdef __cplusplus
extern "C"{
#endif
#include "../lib1/ctest1.h"
#include "../lib2/ctest2.h"
#ifdef __cplusplus
}
#endif

#endif

// note: don't need to include all functions, use include used ones.
extern "C" {
    void ctest1(int* i);
}

void fun1_lib(int *i);
void fun2_lib(int *i);
