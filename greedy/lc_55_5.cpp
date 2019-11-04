/*
 * Jump game
 * https://leetcode.com/problems/jump-game/
 * https://www.cnblogs.com/TenosDoIt/p/3719630.html
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
            int canArrive =0;
            for (int i=0; i<=canArrive && canArrive<nums.size()-1; i++) {
                if (i+nums[i] > canArrive) canArrive = i+nums[i];
            }

            return (canArrive >= nums.size()-1);
        }

};


int main() {
    vector<int> nums={3,2,1,0,4};
    Solution anw;
    if (anw.canjump(nums)) printf("true\n");
    else printf("false\n");

    return 0;
}
