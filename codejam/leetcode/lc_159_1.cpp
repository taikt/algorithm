/*
https://leetcode.com/articles/longest-substring-with-at-most-two-distinct-charac/
*/
// sliding-window

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int i,l,r=0,max_len = 0;
        int n = s.length();
        if (n==0) return 0;
        set<char> m;

        while (r < n && l>-1) {
            if (!m.count(s[r]) && m.size() >= 2) {
                m.erase(m.begin(), m.end());
                for(i=r;i>=0;i--) {
                    if (m.size()>=2 && !m.count(s[i])) break;
                    m.insert(s[i]);
                }
                l=i+1;
            } else {
                m.insert(s[r]);
                max_len = max(max_len,r-l+1);
            }
            r++;
        }

        return max_len;

    }
};

int main() {
    freopen("lc_159.inp","r",stdin);
    freopen("lc_159.out","w",stdout);
    Solution aws;
    string st;
    getline(cin,st);
    cout<<aws.lengthOfLongestSubstringTwoDistinct(st);

    return 0;
}
