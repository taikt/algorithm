/*
 * Jump game
 * https://leetcode.com/problems/jump-game/
 *
 * bottom-up DP method 
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
            if (nums[nums.size()-1] >=1) memo[nums.size()-1]=1; 
            else memo[nums.size()-1] = 0;

            for (int i=nums.size()-2; i>=0; i--)
            {
                int a = i+nums[i], b = nums.size()-1;
                int furtherJump = min(a,b);
                memo[i]=0;
                for (int j=i+1;j<= furtherJump; j++) {
                    if (memo[j]) {
                        memo[i]= 1;
                        break;
                    }
                }
            }

            return memo[0];
        }
};


int main() {
    vector<int> nums={3,2,1,0,4};
    Solution anw;
    if (anw.canjump(nums)) printf("true\n");
    else printf("false\n");

    return 0;
}
