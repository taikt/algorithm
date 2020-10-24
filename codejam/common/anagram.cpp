/*
	Write a method to decide if two strings are anagrams or not.

	Kiểm tra 2 xâu có phải là anagrms.(các ký tự bị đảo lộn)
    ví dụ "abcd" => "dbca" ==> "cbad"
*/

#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm> //std::sort
using namespace std;


void swap1(char &x, char &y) { 
	char z =x; x=y; y=z;
}

void swap2(char *x, char *y) {
	char z =*x; *x=*y; *y=z;
}

int partion(char st[], int start, int end) {
	char pivot = st[end];
	int index = start; // target: a[i] >= pivot with i>=index
	for (int i=start; i< end; i++)
		if (st[i] < pivot) {
			swap1(st[i],st[index]); //can use std::swap here
			index++;
		}

	swap2(&st[index],&st[end]);

	return index;

}

// sort a string using quick sort
void quick_sort(char st[],int start, int end) {
	if (start < end) {
		int index = partion(st,start,end);
		quick_sort(st,start,index-1);
		quick_sort(st,index+1,end);
	}
}

bool isAnagram1(char st1[],char st2[]) {
	quick_sort(st1,0,strlen(st1)-1);
	//quick_sort(st2,0,strlen(st2)-1);
	sort(&st2[0],&st2[0]+strlen(st2)); //using std::sort 
	// printf("%s %s\n",st1,st2);
	//test(st);
	if (!strcmp(st1,st2)) return true;
	else return false;
}

bool isAnagram2(string st1, string st2) {
	sort(st1.begin(),st1.end());
	sort(st2.begin(),st2.end());
	if (st1 == st2)
		return true;
	else return false;
}

// TODO
bool isAnagram3(string st1, string st2) {
	// using character count
}

int main() {

	// char array 
	char st1[] = "adfcb";
	char st2[] = "dfabb";

	if (isAnagram1(st1,st2))
		printf("two strings are anagram\n");
	else 
		printf("two strings are not anagram\n");
	
	// string
	string st3 ="abzt";
	string st4 = "azbtt";
	if (isAnagram2(st3,st4))
		printf("two strings are anagram\n");
	else 
		printf("two strings are not anagram\n");
	
	return 0;
}