/*
 *  g++ two_sum.cpp -std=c++11
 *  https://leetcode.com/problems/two-sum/
 *
 *
 * */ 

#include <vector>
#include <string>
#include <stdio.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap{make_pair(nums[0], 0)};
        
        for (size_t i = 1; i < nums.size(); ++i){
            auto it = hashmap.find(target - nums[i]);
            if (it != hashmap.end() && it->second != i){
                return {it->second, i};
            }
            hashmap[nums[i]] = i;
        }
        
        return {};
    }
};



int main() {
    Solution a;
    vector<int> ans;
    int input[] ={2, 8, 7, 15};
    vector<int> nums(input,input+4); // input + sizeof(input)/sizeof(int)
        
    ans = a.twoSum(nums, 9);
    #if 0
    vector<int>::iterator it;

    for (it=ans.begin(); it!= ans.end(); it++)
        printf("%d ",*it);
    printf("\n");
    #endif
    for (int i=0; i<ans.size(); i++)
        printf("%d ",ans[i]);
    printf("\n");


    return 0;
}
