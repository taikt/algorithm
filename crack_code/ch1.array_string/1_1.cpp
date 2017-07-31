/*
Implement an algorithm to determine if a string has all unique characters. What if you can not use additional data structures? 

xác định 1 string có các ký tự duy nhất hay không.
./a.out "string_input" ==> 1: duy nhất, 0: không duy nhất

*/

#include <stdio.h>
#include <stdlib.h>
#include <cstring>

// string includes characters 'a' -> 'z': 26 characters
// count['a'] = count['b'] = .. = count['z'] = 0;
// 'aabcdez' ==> count['a'] = 2 ==> not unique string

int count[128];

int checkUnique(char st[],int len) {
	printf("%d\n",len);
	for (int i=0; i< len; i++)
	{
		count[st[i]]++;
		if (count[st[i]] >= 2) return 0;
	}

	return 1; 
}

// string include every characters in ASCII

int main() {
	memset(count,0,sizeof(count));
	char st[] = "tesadft";
	int len = sizeof(st);
	printf("%d\n",sizeof(st));

	if (checkUnique(st,len-1) == 1) printf("unique\n");
	else printf("un unique\n");

	return 0;
}