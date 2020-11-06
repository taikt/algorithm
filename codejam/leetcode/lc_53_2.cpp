/*
 * https://leetcode.com/problems/maximum-subarray/
 * https://github.com/grandyang/leetcode/issues/53
 *
 * devide and conque method
 * g++ lc_53_1.cpp --std==c++11
 */

// DP method
//
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        int maxSubArray(vector<int>& nums) {

            return maxSub(0,nums.size()-1,nums);
        }
        
        int maxSub(int left, int right, vector<int>& nums) {
            int mid = left + (right-left)/2, lmax=0, rmax=0, mmax=0;
            if (left>= right) return nums[left];
            lmax = maxSub(left,mid-1,nums);
            rmax = maxSub(mid+1,right,nums);
            //find max sum among [left,right] that contains nums[mid]
            mmax = nums[mid];
            int t= mmax;
            for (int i=mid-1; i>=left; i--) {
                t += nums[i];
                mmax = max(mmax, t);
            }
            t=mmax;
            
            for (int i=mid+1; i<=right; i++) {
                t += nums[i];
                mmax = max(mmax, t);
            } 
            return max(mmax,max(lmax,rmax));
        }

        //optimize: replace F[i] by cursum
};

int main() {
    Solution ans;
    vector<int> v={-2,1,-3,4,-1,2,1,-5,4};
    printf("max sum=%d\n",ans.maxSubArray(v));

    return 0;
}

