/*
    https://leetcode.com/problems/two-sum-iii-data-structure-design/

*/
#include "bits/stdc++.h"
using namespace std;

// design
class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {

    }

    /** Add the number to an internal data structure.. */
    void add(int number) {
        nums.push_back(number);
    }

    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        sort(nums.begin(),nums.end());
        int i=0, j = nums.size()-1;
        while (i != j) {
            if (value > nums[i]+nums[j]) i++;
            else if (value < nums[i]+nums[j]) j--;
            else return true;
        }
        return false;
    }
private:
    vector<int> nums;
};

int main() {
/*
9
6
1 5 6 2 11 3
*/
    freopen("lc_170.inp","r",stdin);
    freopen("lc_170.out","w",stdout);
    int sum,n;
    scanf("%d\n",&sum);
    scanf("%d\n",&n);
    TwoSum* obj = new TwoSum();
    vector<int> nums(n);
    for (int i=0;i<n;i++) {
        scanf("%d",&nums[i]);
        obj->add(nums[i]);
    }

    if (obj->find(sum)) cout<<"found\n";
    else cout<<"not found\n";

    return 0;
}

