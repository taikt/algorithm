// https://leetcode.com/problems/valid-parentheses/
// TODO
// https://leetcode.com/problems/valid-parentheses/discuss/420260/Simplest-C%2B%2B-solution-using-lessvectorgreater-0ms-faster-than-100.00
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        vector<char> buf;
        for (auto i:s) {
           if (i=='(' || i=='{' || i=='[') {
               buf.push_back(i);
               } else {
                if (buf.empty()) return false;
                if (i==')' && buf.back() != '(') return false;
                if (i=='}' && buf.back() != '{') return false;
                if (i==']' && buf.back() != '[') return false;
                buf.pop_back();
               }
        }
        return buf.empty();
    }
};

int main() {
    freopen("lc_20.inp","r",stdin);
    freopen("lc_20.out","w",stdout);
    string s;
    getline(cin,s);
    Solution awn;
    if (awn.isValid(s)) cout<<"true";
    else cout<<"false";

    return 0;
}
