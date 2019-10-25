/*
 * https://leetcode.com/problems/longest-palindromic-substring/
 * https://github.com/grandyang/leetcode/issues/5
 * Longest Palindromic Subsequence II: find the length of the longest palindromic subsequence
 * bottom-up DP
 * L[i,j]: maximum number of characters of a palindromic substring inside [i,j]
 * i.e abbccbx => L[0,6] = 4 (bccb)
 * if (s[i] == s[j]) L[i,j] = L[i+1,j-1] +2 // look not right when insde substring [i+1,j-1] doesn't contain a palindromic
 * else L[i,j] = max(L[i+1,j], L[i,j-1])
 * TODO: solution not correct yet, fix me!
 */


#include <cstdio>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

class Solution {
    public:
        int longestPalindrome(string s) {
            int n = s.size(), maxlen=0, start=0;
            vector<vector<int>> dp(n,vector<int>(n,0));
            for (int i=0; i<n;i++) dp[i][i] = 1;
            
            for (int j=1; j<= n-1; j++) {
                for (int i=j-1; i>=0; i--) {
                    if (s[i]==s[j]) {dp[i][j] = dp[i+1][j-1] +2; printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);}
                    else {dp[i][j] = max(dp[i+1][j], dp[i][j-1]); printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);}
                }
            }
            return dp[0][n-1];
        }
};
int main() {
    Solution anw;
    printf("longest palindronme:%d\n",anw.longestPalindrome("abcbuabnnba"));

    return 0;
}
