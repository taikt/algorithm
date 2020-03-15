// g++ run_test.cpp test-main.cpp ./../linked_list/cci_2.1.h -I./include
#include "include/catch.hpp"
#include "bits/stdc++.h"
//#include "node.h"
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

#if 0
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

#if 0
// cci_2.1
#include "./../linked_list/cci_2.1.h"

TEST_CASE("Chapter 02 - Problem 01 - removeDups()", "test"){
    const std::vector<int> noDups = {1,7,3,6,5,4,2};
    const std::vector<int> dups = {2,2,1,5,6,2,5,2,7,7};
    const std::vector<int> fixedDups = {2,1,5,6,7};
    const std::vector<int> emptyVec;

    // check that remove dups function doesn't affect lists with no dups
    SinglyLinkedNode<int>* noDupsHead = vectorToList(noDups);
    removeDups(noDupsHead);
    REQUIRE(noDups == listToVector(noDupsHead));

    // check case with duplicates
    SinglyLinkedNode<int>* dupsHead = vectorToList(dups);
    removeDups(dupsHead);
    REQUIRE(fixedDups == listToVector(dupsHead));

    // check case with empty list
    SinglyLinkedNode<int>* emptyHead = vectorToList(emptyVec);
    removeDups(emptyHead);
    REQUIRE(emptyVec == listToVector(emptyHead));
}
#endif // 1

#if 0
// g++ run_test.cpp test-main.cpp ./../stack/lc_20_1.cpp -I./include
#include "./../stack/lc_20.cpp"
TEST_CASE("lc_20") {
    Solution4 awn;
    REQUIRE(awn.isValid("{}()")== true);
    REQUIRE(awn.isValid("{}())(")== true);
}
#endif

#if 1
#include "./../linked_list/lc_23.cpp"
TEST_CASE("lc_23") {
    vector<int> l1 = {1,4,5,9};
    vector<int> l2 = {1,3,4};
    vector<int> l3 = {2,6};


    //printList(l);
    vector<ListNode*> lists(3);
    lists[0]= vectorToList(l1);
    lists[1]= vectorToList(l2);
    lists[2]= vectorToList(l3);
    Solution anw;
    ListNode* out = anw.mergeKLists(lists);
    printList(out);

    vector<int> output = listToVector(out);
    vector<int> expect_output ={1,1,2,3,4,4,5,6,9};
    REQUIRE(output == expect_output);
}
#endif // 1
