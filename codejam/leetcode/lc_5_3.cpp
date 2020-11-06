/*
 * https://leetcode.com/problems/longest-palindromic-substring/
 * https://github.com/grandyang/leetcode/issues/5
 * 
 * expand palinddromic string from center
 *
 * abccbm: {c,c} => {bc,cb}:  expand(i,i+1)
 * abcbm: {c} => {bcb}: expand(i,i)
 *
 */

// DP method

#include <cstdio>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        string longestPalindrome(string s) {
            int n = s.size(), maxlen=0, start=0;
            vector<vector<int>> dp(n,vector<int>(n,0));
            
            for (int i=0; i<= n-1; i++) {
                expand(i,i,start,maxlen,s);
                expand(i,i+1,start,maxlen,s);
            }
            return s.substr(start,maxlen);
        }

        void expand(int left, int right, int& start, int& maxlen,string s) {
            while (s[left]== s[right] && left>=0 && right<= s.size()) {
                left--;
                right++;
            }
            if ((right-left-1) > maxlen && (left+1 < right -1)) {
                maxlen = right-1-left;
                start = left+1;
            }
        }
};
int main() {
    Solution anw;
    printf("longest palindronme:%s\n",anw.longestPalindrome("abcbuabnnba").c_str());

    return 0;
}
