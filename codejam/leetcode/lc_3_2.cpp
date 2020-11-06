#include <bits/stdc++.h>
using namespace std;

// sliding-window

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if (n==0) return 0;
        map<char,int> m;
        int i=0,j=0, max_len=0;

        while (i<n && j<n) {
            if (m.count(s[j])) //m.find() != m.end()
            {
                i=max(m[s[j]]+1,i);

            }
            max_len = max(max_len,j-i);
            m[s[j]] = j;
            j++;

        }
        return max_len+1;
    }
};

int main() {
    string st;
    freopen("lc_3.inp","r",stdin);
    freopen("lc_3.out","w",stdout);
    getline(cin,st);
    Solution anw;
    cout<<anw.lengthOfLongestSubstring(st);

    return 0;
}
