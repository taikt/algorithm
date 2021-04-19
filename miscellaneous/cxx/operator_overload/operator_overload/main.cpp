#include "integer.h"
int main() {
	integer a(1), b(3);
	integer sum = a + b; // call plus overloading operator first, then copy constructor later
	cout << sum.getValue() << endl;
}