// https://leetcode.com/problems/valid-parentheses/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> buf;
        for (auto i:s) {
            if (i=='{' || i=='(' || i=='[') buf.push(i);
            else if (i=='}' || i==')' || i==']') {
                if (buf.empty()) return false;
                // ascii
                // ( - 28
                // ) - 29
                // [ - 133
                // ] - 135
                // { - 173
                // } - 175
                int diff = i - buf.top();
                if (diff == 1 || diff==2) buf.pop();
                else return false;
            }
            else return false;
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
