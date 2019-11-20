/*
	https://leetcode.com/problems/longest-consecutive-sequence/
	https://github.com/grandyang/leetcode/issues/128

	Input: [100, 4, 200, 1, 3, 2]
	Output: 4

	solution: use sort
	time complexity: O(nlogn) because using sort().
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
		int cnt=1, max_length=0;
#if 0		
		for (int i=1; i<nums.size(); i++) {
			if (nums[i] > nums[i-1]) {
				if (nums[i] == nums[i-1]+1) {
					cnt++;
					max_length = max(max_length,cnt);
				} else
				cnt=1;
			}
		}
#endif
		for (int i=1; i<nums.size(); i++) {
			if (nums[i] > nums[i-1]) {
				if (nums[i] == nums[i-1]+1) cnt++;
				else {
					max_length = max(max_length,cnt);
					cnt=1;
				} 
			}
		}
		
		return max_length;
	}
};


int main() {
	Solution ans;
	vector<int> v{100,4,200,1,3,2,8,5};
	printf("max length %d\n",ans.longestConsecutive(v));

	return 0;
}