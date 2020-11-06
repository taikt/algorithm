// https://stackoverflow.com/questions/45131717/define-and-expected-primary-expression-error

#include <stdio.h>
#include <pthread.h>
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;



#ifndef DEBUG
#define DEBUG 1
#endif
#define log(fmt,...) do { if (DEBUG) {fprintf(stderr, fmt, ## __VA_ARGS__); fprintf(stderr,"\n");}} while (0)

#if DEBUG

#define log1(...) { \
    char str[100]; \
    sprintf(str,## __VA_ARGS__); \
    printf("[%s][%s:%d] %s\n",__FILE__,__func__,__LINE__,str); \
}

#define log2(...) { \
    char str[100]; \
    sprintf(str,## __VA_ARGS__); \
    std::cout << "[" << __FILE__ << "][" << __FUNCTION__ << "][Line " << __LINE__ << "] " << str << std::endl; \
}

#define log3(fmt,...) \
    do { \
        char str[100]; \
        sprintf(str,fmt,## __VA_ARGS__); \
        fprintf(stderr, "[%s][%s:%d] %s\n",__FILE__,__func__,__LINE__,str); \
    } while (0)

#else
#define log(...)
#define log1(...)
#define log2(...)
#define log3(...)
#endif


int main() {
    printf("hello\n");
    log("hi");
    log1("hi");
    log2("hi");
    log3("hi");
    
    return 0;
}
