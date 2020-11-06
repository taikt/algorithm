#include <bits/stdc++.h>
using namespace std;
// two-pointer

#define FOR(i,a,b) for(int i=a; i<b; i++)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        if (nums.empty() || nums.front()>0 || nums.back()<0) return {};
        int n = nums.size();
        FOR(k,0,n-2) {
            if (nums[k]>0) break;
            if (k>0 && nums[k] == nums[k-1]) continue; // khong kiem tra lai target duplicate,
            // vd 1,2,2,2,4,5 : target 2 chi tinh lan dau
            int target = 0 - nums[k], i=k+1, j=n-1;
            while (i<j) {
                if (nums[i] + nums[j] == target) {
                    res.push_back({nums[k],nums[i],nums[j]});//nums[k]<= nums[i]<=nums[j]
                    while (i<j && nums[i]==nums[i+1]) i++; // xu ly duplicate
                    while (i<j && nums[j]==nums[j-1]) j--; // xu ly duplicate
                    i++; j--;
                } else if (nums[i] + nums[j] > target) j--;
                else i++;
            }
        }
        return res;
    }

    vector<vector<int>> threeSum2(vector<int>& nums) {
        set<vector<int>> res;
        sort(nums.begin(), nums.end());
        if (nums.empty() || nums.front()>0 || nums.back()<0) return {};
        int n = nums.size();
        FOR(k,0,n-2) {
            if (nums[k]>0) break;
            //if (k>0 && nums[k] == nums[k-1]) continue; // khong kiem tra lai target duplicate,
            // vd 1,2,2,2,4,5 : target 2 chi tinh lan dau
            // khong can check khi su dung set, vi cac thanh phan cua tripple da duoc sap xep !
            int target = 0 - nums[k], i=k+1, j=n-1;
            while (i<j) {
                if (nums[i] + nums[j] == target) {
                    res.insert({nums[k],nums[i],nums[j]});//nums[k]<= nums[i]<=nums[j], 1 element la duy nhat, ko duplicate
                    //while (i<j && nums[i]==nums[i+1]) i++; // xu ly duplicate
                    //while (i<j && nums[j]==nums[j-1]) j--; // xu ly duplicate
                    // khong can check duplicate khi su dung set
                    i++; j--;
                } else if (nums[i] + nums[j] > target) j--;
                else i++;
            }
        }
        return vector<vector<int>>(res.begin(),res.end());
    }
};


int main() {
    freopen("lc_15.inp","r",stdin);
    freopen("lc_15.out","w",stdout);
    vector<int> nums;
    string s;
    getline(cin,s);
    stringstream st(s);
    int x;
    while (st>>x) nums.push_back(x);
    Solution anw;
    vector<vector<int>> ret = anw.threeSum(nums);
    FOR(i,0,ret.size()) {
        for (auto x: ret[i])
            cout<<x<<" ";
        cout<<"\n";
    }


    return 0;
}
