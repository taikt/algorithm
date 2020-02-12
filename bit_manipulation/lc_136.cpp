/*
 * https://leetcode.com/problems/single-number/
 * https://github.com/grandyang/leetcode/issues/136
 */
#include <vector>
#include <stack>
#include <cstdio>
#include <unordered_set>
using namespace std;

class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            unordered_set<int> st;
            for (int num: nums) {
                if (st.count(num)) st.erase(num);
                else st.insert(num);
            }

            return *st.begin();
        }
        /*
         * xor operation
         * a^(b^c)= (a^c)^b ?
         * a^0 = a
         * a^a = 0
         * a^a^b = 0^b = b
         */
        int singleNumber2(vector<int>& nums) {
            int res=0;
            for (auto num:nums) {
                res = res ^ num; // res ^= num;
            }
            return res;
        }
};

int main() {
    Solution anw;
    vector<int> num = {1,2,2,3,4,3,4};
    printf("%d\n",anw.singleNumber(num));


    return 0;
}



