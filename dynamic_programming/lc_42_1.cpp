// https://leetcode.com/problems/trapping-rain-water/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int ret =0;
        //if (height == nullptr) return 0;
        int size = height.size();
        vector<int> left_max(size), right_max(size);
        left_max[0] = height[0];
        for (int i=1; i<size; i++) {
            left_max[i] = max (left_max[i-1],height[i]);
        }

        right_max[size-1] = height[size-1];
        for (int i=size-2; i>=0; i--) {
            right_max[i] = max (right_max[i+1],height[i]);
        }

        for (int i=1;i<size-1; i++) {
            ret += min(left_max[i],right_max[i]) - height[i];
        }
        return ret;
    }
};

int main() {
    freopen("lc_42.inp","r",stdin);
    freopen("lc_42.out","w",stdout);
    vector<int> nums;
    string st;
    getline(cin,st);
    stringstream str(st);
    int t;
    while(str>>t)
        nums.push_back(t);

    Solution su;
    cout<<su.trap(nums);


    return 0;
}
