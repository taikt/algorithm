/*
 * https://leetcode.com/problems/maximum-subarray/
 * https://github.com/grandyang/leetcode/issues/53
 *
 * bottom-up DP
 * F[i] = max(ai,ai+F[i-1]);
 *
 * F[i]: maximum sum from [0,i], which subarray contains a[i]
 * F[i] = max {{ai}, {..a(i-1), ai}} 
 *
 * g++ lc_53_1.cpp --std==c++11
 */
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            vector<int> F(nums.size(),0);
            int maxsum =0;
            F[0] = nums[0];
            for (int i=1; i<nums.size(); i++) {
                F[i] = max(F[i-1]+nums[i], nums[i]);
                maxsum = max(F[i], maxsum);
            }
            return maxsum;
        }
        //optimize: replace F[i] by cursum
};

int main() {
    Solution ans;
    vector<int> v={-2,1,-3,4,-1,2,1,-5,4};
    printf("max sum=%d\n",ans.maxSubArray(v));

    return 0;
}

