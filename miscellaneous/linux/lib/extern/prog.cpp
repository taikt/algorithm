// Suppose that we already exported shared lib compiled in gcc
// g++ prog.cpp -lctest

#include <cstdio>
using namespace std;

extern "C" {
void ctest1(int *);
void ctest2(int *);
}

int main() {
	int x;
	
	ctest1(&x);
	printf("%d\n",x);

	return 0;
}
