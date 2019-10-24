/*
 * https://leetcode.com/problems/longest-palindromic-substring/
 * https://github.com/grandyang/leetcode/issues/5
 *
 * top down DP
 * L[i,j]: true if [i,j] is a palindromic substring
 *
 *
 *
 */


#include <cstdio>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        string longestPalindrome(string s) {
            int n = s.size(), maxlen=0, start=0;
            vector<vector<int>> dp(n,vector<int>(n,-1));
            for (int i=0; i<n;i++) dp[i][i] = 1;

            for (int j=0; j<=n-1; j++) {
                for (int i=0; i<j;i++)
                {
                    dp[i][j] = getDP(i,j,dp,s);
                    if (dp[i][j] && (j-i+1 > maxlen)) {
                        maxlen = j-i+1;
                        start = i;
                    }
                }
            }
            return s.substr(start,maxlen);

        }

        int getDP(int i, int j, vector<vector<int>>& dp,string s) {
            if (dp[i][j] != -1) return dp[i][j];
            if (j==i+1) return (s[i] == s[j]);
            else
                return (getDP(i+1,j-1,dp,s) && (s[i]==s[j]));
        }

};
int main() {
    Solution anw;
    printf("longest palindronme:%s\n",anw.longestPalindrome("abcbuabnnba").c_str());

    return 0;
}
