/*
	greedy method
	https://github.com/grandyang/leetcode/issues/376
	https://leetcode.com/problems/wiggle-subsequence/solution/

*/
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		int up=1, down=1, n=nums.size();
		for (int i=1; i < n; i++) {
			if (nums[i] > nums[i-1]) up = down +1;
			else if (nums[i] < nums[i-1]) down = up + 1;
		}
		return min(n,max(up,down));

	}
};


int main() {
	Solution anw;
	vector<int> v={8,2,3,4,5};
	printf("%d\n",anw.wiggleMaxLength(v));

	return 0;
}
