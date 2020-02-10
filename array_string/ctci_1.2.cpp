/*
Write code to reverse a C-Style String. (C-String means that “abcd” is represented as five characters, including the null character.)

Thực hiện đảo một xâu.
"abc" ==> "cba"
*/
// https://stackoverflow.com/questions/3796181/c-passing-pointer-to-function-howto-c-pointer-manipulation


#include <stdio.h>
#include <stdlib.h>

void swap(char* x, char* y) {
	char z;
	z = *x;
	*x = *y;
	*y = z;
}

void swap2(char &a, char &b) { // pass by reference, only for C++, not C
	/* 
	a = a^b; // 1st way
	b = a^b;
	a = a^b;
	*/
	char z;  // 2rd way
	z =a; a=b; b=z;
}

void reverseString(char* st) {
	//for (int i=0; i<len; i++)
	//	printf("%c ",st[i]);
	printf("%p\n",st);
	char *end = st;
	char *start = st;
	printf("end=%p, start=%p\n",end, start);

	while (*end != '\0') // or while (*end) {}
	{
		printf("%c ",*end);
		end++;
		// end = end +1;
	}
	end--;
	//end = end - 1;

	//printf("%c\n",*end);

	while (start < end) {
		//swap(start,end); // 1st way
		//start++;
		//end--;
		
		//swap(start++, end--); // 2rd way
		
		//swap2(*start, *end); // 3nd way
		//start++; end--;

		swap2(*start++, *end--); // 4th way
	}
	
}


int main() {
	char test[] = "abcdt";
	reverseString(test); 
	printf("%p\n",&test[0]);
	printf("%s\n",test);

	return 0;
}