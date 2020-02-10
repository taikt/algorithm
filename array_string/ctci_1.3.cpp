/*
Design an algorithm and write code to remove the duplicate characters in a string without 
using any additional buffer. NOTE: One or two additional variables are fine. An extra copy 
of the array is not. FOLLOW UP Write the test cases for this method.

Xóa ký tự trùng lặp trong 1 string, không sử dụng bộ đệm thêm
"abcbdf" ==> "abcdf"
*/

#include <iostream>
#include <cstring>
#include <bitset>
using namespace std;

//O(n^2)
string deleteDuplicate1(string st) {

	string result="";
	//printf("%d\n",strlen(st)); // if argument is char* st or char st[]
	
	for (int i=0; i< st.length(); i++)
	{
		if (st[i] != '\0')
		{
			result += st[i];
			for (int j=i+1; j<st.length(); j++) {
				if (st[i] == st[j]) st[j] = '\0'; 
			}
		}
	}
	

	return result;
}

string deleteDuplicate2(string st) {

	string result = "";
	//char s[];
	bitset<32> bits(0);
	//int p = 0;
	
	for (int i=0; i<st.length(); i++) {
		if (!bits.test(st[i] - 'a')) {
			result += st[i];
			//st[p++] = st[i];
			bits.set(st[i] - 'a');
		}
	}
	st[p]='\0';

	return result;
	//return st;
}

int main() {

	string st ="xyzyy";
	//char st[] ="xyzzy";
	/*
	// debug
	st += 'a';
	st += 'b';
	printf("%s",st.c_str());
	*/
	st = deleteDuplicate2(st);
	printf("%s\n",st.c_str());

	return 0;
}