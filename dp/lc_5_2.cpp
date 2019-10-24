/*
 * https://leetcode.com/problems/longest-palindromic-substring/
 * https://github.com/grandyang/leetcode/issues/5
 *
 * bottom-up DP
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
            vector<vector<int>> dp(n,vector<int>(n,0));
            for (int i=0; i<n;i++) dp[i][i] = 1;
            
            for (int j=1; j<= n-1; j++) {
                for (int i=0; i<j; i++) {
                            dp[i][j] = (dp[i+1][j-1] || (j==i+1)) && (s[i] == s[j]);
                            if (dp[i][j] && (maxlen < j-i+1)) {
                                maxlen = j-i+1;
                                start = i;
                            }
                }
            }
            return s.substr(start,maxlen);
        }
};
int main() {
    Solution anw;
    printf("longest palindronme:%s\n",anw.longestPalindrome("abcbuabnnba").c_str());

    return 0;
}
