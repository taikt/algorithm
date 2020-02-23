/*
Implement an algorithm to determine if a string has all unique characters. What if you can not use additional data structures?

xác định 1 string có các ký tự duy nhất hay không.

string includes characters 'a' -> 'z': 26 characters
TODO: string include all ASCII characters

*/

#include <stdio.h>
#include <stdlib.h>
#include <cstring> // for memset
#include <iostream>  // for string
#include <bitset> // to use bitset, need bitset and vector libs
#include <vector>
using namespace std;

// solution 0_1: no use data structure
int checkUnique0_1(char st[],int len) {
	for (int i=0; i< len-1; i++)
		for (int j=i+1; j< len; j++) {
			if (st[i] == st[j]) return 0;
		}
	return 1;
}

/// solution 0: no use data structure
int checkUnique0_2(char* st,int len) {
	// if input called like, char st[] = "tesadf" ==> always use this type
	// no problem to modify st[i]
	// if input called like, char* st = "tesadf";
	// segment fault to modify st[i]

	for (int i=0; i< len-1; i++)
		for (int j=i+1; j< len; j++) {
			if (st[i] == st[j]) return 0;
		}
	return 1;
}



// solution 1
// init: count['a'] = count['b'] = .. = count['z'] = 0;
// 'aabcdez' ==> count['a'] = 2 ==> not unique string
int checkUnique1(char st[],int len) {
	printf("%d\n",len);
	int count[128];
	memset(count,0,sizeof(count));

	for (int i=0; i< len; i++)
	{
		count[st[i]]++;
		if (count[st[i]] >= 2) return 0;
	}

	return 1;
}

// solution 2
// init: count['a'] = count['b'] = .. = count['z'] = false;
// 'aabcdez' ==> count['a'] = true ==> not unique string

int checkUnique2(char st[],int len) {
	printf("%d\n",len);
	int count[32];
	memset(count,0,sizeof(count));

	for (int i=0; i< len; i++)
	{
		if (count[st[i]-'a']) return 0;
		count[st[i]-'a'] = true;
	}

	return 1;
}

// solution 3: use bitwise operation
int checkUnique3(char st[],int len) {
	printf("%d\n",len);
	int x = 0;
	for (int i=0; i< len; i++)
	{
		if (x & (1 << (st[i] - 'a'))) return 0;
		x = x | (1 << (st[i] - 'a'));
	}

	return 1;
}

// solution 4_1: similar solution2 in cpp style
int checkUnique4_1(const string& s) { //checkUnique4(string s) is ok
	int len = s.length();
	printf("%d\n",len);
	bool count[32];
	memset(count,0, sizeof(count));

	for (int i=0; i< len; i++)
	{
		if (count[s[i]-'a']) return 0;
		count[s[i]-'a'] = true;
	}

	return 1;
}


// solution 4_2: similar solution2 in cpp style, use vector instead of array
int checkUnique4_2(const string& s) { //checkUnique4(string s) is ok
	int len = s.length();
	printf("%d\n",len);
	vector<bool> count(32); //default, all count[i] == false

	for (int i=0; i< len; i++)
	{
		if (count[s[i]-'a']) return 0;
		count[s[i]-'a'] = true;
	}

	return 1;
}

// solution 5: use bitset
bool checkUnique5(string s) {
	bitset<32> bits(0);
	int len = s.length();
	for (int i=0; i< len; i++) {
		if (bits.test(s[i]-'a')) return false;
		bits.set(s[i]-'a');
	}
	return true;
}

bool isUnique(const std::string& input) {
    std::bitset<128> asciiTable;
    for (char character : input) {
        if (asciiTable[(int) character]) {  // if character already exists in "hash table"
            return false;
        }
        asciiTable.flip((int) character);
    }
    return true;
}

#if 0
int main() {

	char st[] = "tesadf"; // should not use char* st = "tesadf"; if modify st[i] can lead segment fault

	int len = sizeof(st);

	if (checkUnique0_2(st,len-1) == 1) printf("unique\n\n");
	else printf("un unique\n\n");

	string st1="tesadf";
	if (checkUnique4_2(st1) == 1) printf("unique\n");
	else printf("un unique\n");

	return 0;
}
#endif
