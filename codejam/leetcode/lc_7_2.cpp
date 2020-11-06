// https://leetcode.com/problems/reverse-integer/
// Assume we are dealing with an environment which
// could only store integers within the 32-bit signed integer range: [-231,  231 - 1]
// For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
// math

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool negative=false;
        int ret=0;
        if (x <0) {x *= -1; negative = true;}
        string s = to_string(x);
        std::reverse(s.begin(),s.end());
        ret = stoi(s);
        ret = negative ? -ret:ret;
        return ret;
    }
};

int main() {
    freopen("lc_7.inp","r",stdin);
    freopen("lc_7.out","w",stdout);
    int n;
    scanf("%d",&n);
    Solution su;
    cout<<su.reverse(n);

    return 0;
}
