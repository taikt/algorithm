#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a; i<b; i++)

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int closest = nums[0] + nums[1] + nums[2];
		int diff = abs(closest -target);
		sort(nums.begin(),nums.end());
		FOR(i,0,nums.size()-2) {
			int left = i+1, right = nums.size() -1;
			while (left <right) {
				int sum = nums[i] + nums[left] + nums[right];
				int newDiff = abs(sum - target);
				if (diff > newDiff) {
					diff = newDiff;
					closest = sum;
				}
				if (sum<target) left++;
				else right--;
			}

		}
		return closest;
	}

};


int main() {
    freopen("lc_16.inp","r",stdin);
    freopen("lc_16.out","w",stdout);
    int t,target;
    scanf("%d\n",&target);
    string st;
    vector<int> nums;
    getline(cin,st);
  
    stringstream str(st);
    while (str>>t)
    	nums.push_back(t);
    Solution su;
    cout<<su.threeSumClosest(nums,target);

    return 0;
}