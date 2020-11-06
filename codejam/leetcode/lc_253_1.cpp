/*
*  https://github.com/grandyang/leetcode/issues/253
*
*  Solution: sap xep dau vao tang dan: 2, 4, 7, 10
*   danh dau: {7,10} => (1,-1)
*  => 2(1), 4(-1), 7(1), 10(-1) => minMeetingroom = 1
* minMeetingroom = max(res, room += value(1 or -1))
*	use map (BST strucutre): travel in a map by default: Left -> Root-> Right => duyet theo tang dan
*
* https://www.geeksforgeeks.org/map-vs-unordered_map-c/
* https://stackoverflow.com/questions/25468020/stdmap-and-binary-search-tree
* map: BST tree, ordered_map: hash table
*/

// greedy
#include <vector>
#include <stack>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
    public:
	    int minMeetingRooms(vector<vector<int>>& intervals) {
	    	map<int,int> m;
	    	for (auto a: intervals) {
	    		// for [start,end] time: m[start] = 1; m[end] = -1
	    		++m[a[0]];
	    		--m[a[1]];
	    		printf("a[0]=%d, a[1]=%d => %d,%d\n",a[0],a[1],m[a[0]],m[a[1]]);
	    	}
	    	int rooms = 0, res=0;
	    	for (auto it:m) {
	    		res = max(res, rooms += it.second);
	    		//printf("%d(value=%d)\n",it.first,it.second);
	    		//printf("[%d=> %d]\n", it.second, rooms);
	    	}
	    	return res;

	    }
};

// test map
void test_map() {
	map<int,int> m;
	//add map
	m[2] = 1;
	m[7] = 1;
	m[8] = -1;
	m[3] = 0;
	// map created below (BST)
	//           2(1)
	//                7(1)
	//            3(0)    8(-1)
	for (auto it:m) {
		printf("%d(value=%d)\n",it.first,it.second);
		// L-Root-R: 2->3->7->8
	}
}

int main() {
	Solution anw;
	vector<vector<int>> intervals= {
		{7,10},
		{2,4}
	};
	printf("%d\n",anw.minMeetingRooms(intervals));

	//test_map();

    return 0;
}
