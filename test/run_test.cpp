#include "include/catch.hpp"
#include "bits/stdc++.h"
using namespace std;

#if 0
// cci_5.4
int next(int x);
int previous(int x);
int next(int x);
int previous(int x);
TEST_CASE("nextNumber()", "test"){
    REQUIRE(next(0b0001) == -1);
    REQUIRE(next1(0b0001) == 0b0010);
    REQUIRE(next(0b0100) == 0b0010);
    REQUIRE(next1(0b0100) == 0b1000);
    REQUIRE(previous(0b10011110000011) == 0b10011101110000);  // example from textbook
    REQUIRE(next1(0b11011001111100) == 0b11011010001111);  // example from textbook
}
#endif // 0

#if 0
// cci_1.1
bool isUnique(const std::string& input);
TEST_CASE("Chapter 01 - Problem 01 - isUnique()", "test"){
    REQUIRE(isUnique("alex"));
    REQUIRE(!isUnique("axlex"));
}
#endif // 0

#if 0
//cci_1.2
bool isPermutation(const std::string& s1, const std::string& s2);

TEST_CASE("Chapter 01 - Problem 02 - isPermutation()", "test"){
    REQUIRE(!isPermutation("alex", "aalex"));
    REQUIRE(isPermutation("alex", "xela"));
    REQUIRE(!isPermutation("aabb", "aaaa"));
    REQUIRE(!isPermutation("aaaa", "aabb"));
    REQUIRE(!isPermutation("aaaa", "aa"));
    REQUIRE(isPermutation("", ""));
}
#endif // 0

#if 0
// cci_1.3
void URLify(std::string& input);
TEST_CASE("Chapter 01 - Problem 03 - URLify()", "test") {
	// expect 'Mr. John Smith' -> 'Mr.%20John%20Smith'
	std::string input1 = "Mr. John Smith ";
    std::string input2 = "";
    std::string input3 = " ";
    std::string input4 = "Alex";
    const std::string expectedOutput1 = "Mr.%20John%20Smith%20";
    const std::string expectedOutput2 = "";
    const std::string expectedOutput3 = "%20";
    const std::string expectedOutput4 = "Alex";
	URLify(input1);
    URLify(input2);
    URLify(input3);
    URLify(input4);
	REQUIRE(input1 == expectedOutput1);
	REQUIRE(input2 == expectedOutput2);
	REQUIRE(input3 == expectedOutput3);
	REQUIRE(input4 == expectedOutput4);
}

#endif // 1

#if 0
// cci_1.4
bool palindromePermutation(const std::string& input);
TEST_CASE("Chapter 01 - Problem 04 - palindromePermutation()", "test") {
	REQUIRE(palindromePermutation("tact coa"));
	REQUIRE(!palindromePermutation("Tact Coa"));
	REQUIRE(!palindromePermutation("xyz"));
	REQUIRE(palindromePermutation("AA  B AA"));
	REQUIRE(!palindromePermutation("aA  B AA"));
}
#endif // 1

#if 0
// cci_1.6
string compress(string str);
TEST_CASE("Chapter 01 - Problem 06 - stringCompression()", "test"){
    REQUIRE("a2b1c5a3" == compress("aabcccccaaa"));
    REQUIRE("alex" == compress("alex"));
    REQUIRE("" == compress(""));
    REQUIRE("a10" == compress("aaaaaaaaaa"));
}
#endif // 1

#if 1
vector<vector<int>> rotate1(vector<vector<int>>& matrix, int N);
vector<vector<int>> inp = {{1, 2, 3, 4},
                           {1, 2, 3, 4,},
                           {1, 2, 3, 4,},
                           {1, 2, 3, 4,}
                          };
vector<vector<int>> out = {{1, 1, 1, 1},
                           {2, 2, 2, 2,},
                           {3, 3, 3, 3,},
                           {4, 4, 4, 4,}
                          };
TEST_CASE("Chapter 01 - Problem 06 - stringCompression()", "test") {
    REQUIRE(rotate1(inp,4)==out);
}

#endif // 1
