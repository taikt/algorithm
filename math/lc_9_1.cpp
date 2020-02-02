// https://leetcode.com/problems/palindrome-number/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        string s1 = to_string(x);
        string s2 = to_string(x);
        std:reverse(s2.begin(),s2.end());
        if (s1==s2) return true;

        return false;
    }
};

int main() {
    freopen("lc_9.inp","r",stdin);
    freopen("lc_9.out","w",stdout);
    int n;
    scanf("%d",&n);
    Solution su;
    if (su.isPalindrome(n)) cout<<"true";
    else cout<<"false";


    return 0;
}
