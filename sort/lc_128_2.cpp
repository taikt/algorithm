/*
	https://leetcode.com/problems/longest-consecutive-sequence/
	https://github.com/grandyang/leetcode/issues/128

	Input: [100, 4, 200, 1, 3, 2]
	Output: 4

	solution: use sort
	time complexity: O(nlogn)
*/

#include <cstdio>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		sort(nums.begin(),nums.end()); // ascending order
		//sort(nums.begin(),nums.end(),greater<int>()); //decreasing order
		for (int i=0; i<nums.size(); i++)
			printf("%d ", nums[i]);

		//return max_length;
	}
};


int main() {
	Solution ans;
	vector<int> v{100,4,200,1,3,2,8};
	printf("max length %d\n",ans.longestConsecutive(v));

	return 0;
}