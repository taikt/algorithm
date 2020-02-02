// https://leetcode.com/problems/palindrome-number/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        } else if (x>=0 && x<10) {
            return true;
        } else {
            long long int rev =0, temp=x;
            while (temp != 0) {
                if (rev> INT_MAX/10) return false; // check overflow
                rev = rev *10 + temp %10;
                temp /= 10;
            }
            return rev == x;
        }
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
