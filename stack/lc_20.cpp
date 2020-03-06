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

class Solution2 {
public:
    bool isValid(string s) {
        stack<char> buf;
        for (auto i:s) {
            if (i=='{' || i=='(' || i=='[') buf.push(i);
            else if (i=='}' || i==')' || i==']') {
                if (buf.empty()) return false;
                int x = buf.top();
                buf.pop();
                switch (i) {
                case '}':
                    if (x != '{') return false;
                    break;

                case ')':
                    if (x != '(') return false;
                    break;

                case ']':
                    if (x != '[') return false;
                    break;
                default:
                    return false;
                }
            }
            else return false;
        }
        return buf.empty();
    }
};

class Solution3 {
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

class Solution4 {
public:
    bool isValid(string s) {
        const  unordered_map<char, char> symbol_pair = {{')', '('},
                                                        {']', '['},
                                                        {'}', '{'}};
        stack<char> parentheses;
        for (const auto& c: s) {
            const auto& it = symbol_pair.find(c);
            if (it != symbol_pair.cend()) {
                if (parentheses.empty() ||
                    parentheses.top() != it->second) {
                    return false;
                }
                parentheses.pop();
            } else {
                parentheses.emplace(c);
            }
        }
        return parentheses.empty();
    }
};

#if 0
int main() {
    freopen("lc_20.inp","r",stdin);
    freopen("lc_20.out","w",stdout);
    string s;
    getline(cin,s);
    Solution4 awn;
    if (awn.isValid(s)) cout<<"true";
    else cout<<"false";

    return 0;
}
#endif
