/*
 *  g++ two_sum.cpp -std=c++11
 *  https://leetcode.com/problems/two-sum/
 *  Variant: chi kiem tra ton tai cap so, khong can tra lai index
 *  phuong phap: two pointers
 * */

#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a; i<b; i++)

class Solution {
public:
    bool twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int t = nums[0];
        sort(nums.begin(),nums.end());

//        FOR(i,0,n) {
//            cout<<nums[i]<<" ";
//        }
//        cout<<"\n"<<target;


        int i=0,j=n-1;
        while (i!=j) {
            if (target > nums[i] + nums[j]) i++;
            else if (target < nums[i] + nums[j]) j--;
            else return true;
        }

        return false;
    }
};



int main() {
    freopen("lc_1.inp","r",stdin);
    freopen("lc_1.out","w",stdout);
    int target,n;
    scanf("%d %d\n",&target,&n);
    vector<int> sums(n);
    for (int i=0; i<n; i++)
        scanf("%d",&sums[i]);
    Solution anw;
    if (anw.twoSum(sums,target)) cout<<"exist\n";
    else cout<<"not exist\n";
    cout<<"hello";
    return 0;
}
