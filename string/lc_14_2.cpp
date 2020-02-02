#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i=a;i<b;i++)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        /*
        for (auto x:strs) {
            cout<<x<<" ";
        }
        cout<<"\n";
        */
        // vertical scanning
        string res = "";
        if (strs.empty()) return "";
        FOR(j,0,strs[0].size()) {
            char c = strs[0][j];
            FOR(i,1,strs.size()) {
                if (j >= strs[i].size() || strs[i][j] != c)
                    return res;
            }
            res.push_back(c);
        }
        return res;
    }
};

int main() {
    freopen("lc_14.inp","r",stdin);
    freopen("lc_14.out","w",stdout);

    string st,word;
    vector<string> strs;
    getline(cin,st);
    stringstream str(st);
    while (str>>word)
        strs.push_back(word);

    Solution s;
    cout<<s.longestCommonPrefix(strs);

    return 0;
}
