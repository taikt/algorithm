/*
	https://leetcode.com/problems/longest-consecutive-sequence/
	https://github.com/grandyang/leetcode/issues/128

	Input: [100, 4, 200, 1, 3, 2]
	Output: 4

	solution: use unordered_set (hashing)
	time complexity: O(n)
*/

#include <cstdio>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_set<int> s(nums.begin(),nums.end());
		int max_length = 0;
		for (int num: nums) {
			if (!s.count(num)) continue;
			s.erase(num);
			int up = num+1, down = num-1;
			while (s.count(up)) s.erase(up++);  
			while (s.count(down)) s.erase(down--);
			max_length = max(max_length,up-down -1); 
		}

		return max_length;
	}
};


int main() {
	Solution ans;
	vector<int> v{100,4,200,1,3,2,8};
	printf("max length %d\n",ans.longestConsecutive(v));

	return 0;
}