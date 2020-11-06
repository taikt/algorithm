/*
	greedy method
	https://leetcode.com/problems/wiggle-subsequence/solution/
	Nhan xet: chuoi wiggle gom cac dinh peak, valley
	vd {8,2,3,4,5} => {8,2,5}: cac dinh trung gian 3,4 khong thuoc chuoi wiggle

*/
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		int n = nums.size();
		int sign = 0, maxLen=1;
		for (int i=1; i<n; i++) {
			if ((nums[i] > nums[i-1]) && (sign != 1)) { //peak
				++maxLen;
				sign = 1;
			}
			else if ((nums[i] < nums[i-1]) && (sign != -1)) { //valley
				++maxLen;
				sign = -1;
			}
		}

		return maxLen;
	}
};


int main() {
	Solution anw;
	vector<int> v={8,2,3,4,5};
	printf("%d\n",anw.wiggleMaxLength(v));

	return 0;
}
