/*
 *  g++ two_sum.cpp -std=c++11
 *  https://leetcode.com/problems/two-sum/
 *
 *
 * */

#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a; i<b; i++)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        FOR(i,0,n) {
            cout<<nums[i]<<" ";
        }
        return {};
    }
};



int main() {
    freopen("lc_1.inp","r",stdin);
    freopen("lc_1.out","w",stdout);
    int sum,n;
    scanf("%d %d\n",&sum,&n);
    vector<int> sums(n);
    for (int i=0; i<n; i++)
        scanf("%d",&sums[i]);
    Solution anw;
    vector<int> out = anw.twoSum(sums,sum);

    return 0;
}
