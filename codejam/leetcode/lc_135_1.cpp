/*
 * Candy
 * https://leetcode.com/problems/candy/
 * https://github.com/grandyang/leetcode/issues/135
 *
 * [1,0,2] => 5 (2,1,2) 
 * [1,2,2] => 4 (1,2,1)
 *
 */
// greedy
//
#include <vector>
#include <stack>
#include <cstdio>
using namespace std;

class Solution {
    public:
    int getCandy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candy(n,1);
        int num=0;
        for (int i=0; i<n;i++) 
            if (ratings[i+1] > ratings[i]) ++candy[i+1];

        for (int j=n-1; j>0;j--) 
            if (ratings[j] < ratings[j-1]) candy[j-1] = max(candy[j-1], candy[j-1]+1); 

        for (int i=0;i<n;i++) num += candy[i];

        return num;

        
    }
};

int main() {
    Solution aws;
    vector<int> ratings={1,2,2};
    printf("%d\n",aws.getCandy(ratings));

    return 0;

}


