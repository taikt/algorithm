/*
 * Jump game
 * https://leetcode.com/problems/jump-game/
 * https://github.com/grandyang/leetcode/issues/55
 *
 * greedy method 
 * time: o(n), space: O(1)
 */

#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
using namespace std;

class Solution {
    public:
        bool canjump(vector<int>& nums) {
            int lastPos;
            for (int i=nums.size()-1; i>=0; i--) {
                if (i+nums[i] >= lastPos)
                    lastPos = i;
            }

            return (lastPos ==0);
        }

};


int main() {
    vector<int> nums={3,2,1,0,4};
    Solution anw;
    if (anw.canjump(nums)) printf("true\n");
    else printf("false\n");

    return 0;
}
