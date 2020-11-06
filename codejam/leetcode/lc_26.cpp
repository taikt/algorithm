/*
    https://leetcode.com/problems/remove-duplicates-from-sorted-array/
    input: Given nums = [0,0,1,1,1,2,2,3,3,4]
    output: {0,1,2,3,4}, length=5
*/
// two-pointer
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j=0;
        if (nums.size() ==0) return 0;
        //for (int i=0; i<nums.size(); i++)
          //  cout<<nums[i]<<" ";
        //cout<<"\n";

        for (int i=1; i<nums.size(); i++) {
            if (nums[j] != nums[i]) {
                j++;
                nums[j] = nums[i];
            }
        }
        return (j+1);
    }

};


int main() {
    freopen("lc_26.inp","r",stdin);
    freopen("lc_26.out","w",stdout);
    vector<int> nums;
    string st;
    getline(cin,st);
    stringstream str(st);
    int t;
    while(str>>t)
        nums.push_back(t);

    Solution anw;
    int len = anw.removeDuplicates(nums);
    cout<<len<<"\n";
    for (int i=0; i<len; i++)
            cout<<nums[i]<<" ";
        cout<<"\n";

    return 0;
}
