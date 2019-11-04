/*
 * Candy
 * https://leetcode.com/problems/candy/
 * https://github.com/grandyang/leetcode/issues/135
 *
 * [1,0,2] => 5 (2,1,2) 
 * [1,2,2] => 4 (1,2,1)
 *
 */

#include <vector>
#include <stack>
using namespace std;

class Solution {
    int candy(vector<int>& ratings) {
        n = ratings.size();
        vector<int> candy(n,1);
        for (int i=0; i<n;i++) 
            if (ratings[i+1] > ratings[i]) ++candy[i+1];

        for (int j=n-1; j>0;j--) 
            if (ratings[j] < ratings[j-1]) 

        
    }
};

int main() {
    Solution aws;

}


