// https://leetcode.com/problems/reverse-bits/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string s = bitset<32>(n).to_string();
        reverse(s.begin(),s.end());
        bitset<32> bs(s);
        return bs.to_ulong();
    }
};

int main() {
    freopen("lc_190.inp","r",stdin);
    freopen("lc_190.out","w",stdout);
    int n;
    scanf("%d",&n);
    Solution su;
    cout<<su.reverseBits(n);

    return 0;
}
