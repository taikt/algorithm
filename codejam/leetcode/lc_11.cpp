/*
    https://leetcode.com/problems/container-with-most-water/
*/

// two-pointer
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ret = INT_MIN;
        for (int i=0, j=height.size()-1;i<j;) {
            ret = max(ret, (j-i)*min(height[i],height[j]));
            if (height[i]<height[j]) i++;
            else if (height[i] > height[j]) j--;
            else return ret; //height[i] = height[j]
        }
        return ret;
    }
};


int main() {
    freopen("lc_11.inp","r",stdin);
    freopen("lc_11.out","w",stdout);
    vector<int> nums;
    string st;
    getline(cin,st);
    stringstream str(st);
    int t;
    while(str>>t)
        nums.push_back(t);

    Solution anw;
    cout<<anw.maxArea(nums);


    return 0;
}
