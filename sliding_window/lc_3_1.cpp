#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        vector<char> m;
        int j=0, max_len=0;

        while (j<n) {
            auto it=find(m.begin(),m.end(),s[j]); // if m is set, can use m.find(s[j])
            if ( it != m.end()) //m.count(s)
            {
                it++;
                m.erase(m.begin(),it);
                //after erase: m[*(it+1),..end], next position from where s[j] occurs

            }
            m.push_back(s[j]);
            j++;
            max_len = max(max_len,(int)m.size());
        }
        return max_len;
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
