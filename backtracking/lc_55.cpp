/*
 * Jump game
 * https://leetcode.com/problems/jump-game/
 *
 * backtracking method
 * time: o(2^n), space: O(n)
 */

#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
using namespace std;

class Solution {
    public:
        bool canjump(vector<int>& nums) {
            return canJumpFrom(0, nums);
        }

        bool canJumpFrom(int pos, vector<int>& nums) {
            if (pos == (nums.size() -1)) return true;
            int a = pos+nums[pos], b = nums.size()-1;
            int furtherJump = min(a,b);
            for (int next=pos+1; next<= furtherJump; next++) {
                if (canJumpFrom(next,nums)) return true;
            }
            return false;
        }
};


int main() {
    vector<int> nums={3,2,1,0,4};
    Solution anw;
    if (anw.canjump(nums)) printf("true\n");
    else printf("false\n");

    return 0;
}
