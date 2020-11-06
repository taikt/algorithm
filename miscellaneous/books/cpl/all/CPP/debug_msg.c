#include "stdio.h"
#include "stdlib.h"

#define DEBUG 
#define debug_print(fmt,...) do { if (DEBUG) fprintf(stderr, fmt, __VA_ARGS__); } while (0)
	
	
int main()
{
	printf("hello");
	debug_print("%s\n","hello");
}	