/*
    https://leetcode.com/problems/remove-duplicates-from-sorted-array/
    input: nums = [3,2,2,3], val = 3,
    output: {2,2}, length=2
*/
// two-pointer
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums,int val) {
        int j=0;
        if (nums.size() ==0) return 0;

        for (int i=0; i<nums.size(); i++) {
            if (nums[i] != val) {
                nums[j] = nums[i];
                j++;
            }
        }
        return (j);
    }

};


int main() {
    freopen("lc_27.inp","r",stdin);
    freopen("lc_27.out","w",stdout);
    vector<int> nums;
    int n,value;
    scanf("%d\n",&value);
    string st;
    getline(cin,st);
    stringstream str(st);
    int t;
    while(str>>t)
        nums.push_back(t);

    Solution anw;
    int len = anw.removeElement(nums,value);
    cout<<len<<"\n";
    for (int i=0; i<len; i++)
            cout<<nums[i]<<" ";
        cout<<"\n";

    return 0;
}
