/*
 * Jump game
 * https://leetcode.com/problems/jump-game/
 *
 * top-down DP method 
 * time: o(n^2), space: O(n)
 */

#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
using namespace std;

class Solution {
    public:
        bool canjump(vector<int>& nums) {
            vector<int> memo(nums.size(), -1);
            // -1: unknown state
            // 1: good position, which can jump to final index
            // 0: bad position, cannot jump to final index
            return canJumpFrom(0, nums,memo);
        }

        bool canJumpFrom(int pos, vector<int>& nums, vector<int>& memo) {
            //if (pos == (nums.size() -1)) return true;
            if (memo[pos] != -1)
                return (memo[pos] == 1) ? true:false;

            int a = pos+nums[pos], b = nums.size()-1;
            int furtherJump = min(a,b);
            for (int next=pos+1; next<= furtherJump; next++) {
                if (canJumpFrom(next,nums,memo)) {
                    memo[pos] = 1;
                    return true;
                }
            }
            memo[pos] = 0;
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
