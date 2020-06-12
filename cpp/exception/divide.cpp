#include <cstdio>

double division(int a, int b) {
	if (b==0) {
		throw "division by zero";
	}
	return a/b;
}

int main() {

	int x=50;
	int y=0;
#if 0
	try {
		// printf("value=%f\n",division(x,y));
		if (y==0) throw "division to zero";
			printf("%f\n",(double)x/y);

	} catch (const char* msg) {
		printf("%s\n",msg);
	}
#endif
	try {
		throw(12);

	} catch (int i) {
		printf("%d\n",i);
		throw;
	}

	return 0;
}