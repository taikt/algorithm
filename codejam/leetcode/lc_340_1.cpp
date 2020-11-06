/*
https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/

Solution:
    slide window + hashmap
*/

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s,int k) {
        int i=0,l=0,r=0,max_len = 0;
        int temp = 0;
        int n = s.length();
        if (n==0) return 0;
        unordered_map<char,int> m;
        while (r<n) {
            m[s[r]] = r; // danh dau vi tri xuat hien cuoi cung cua s[r]
            while (m.size()>k && r>=l) {
#if 0 // way 1: wrong in case 'abaccc': khong xoa 'b'
                temp = l;
                l = m[s[l]]+1;
                m.erase(s[temp]);
#else // way 2
                if (m[s[l]] == l) m.erase(s[l]);
                l++;
#endif // 1
            }

            max_len = max(max_len,r-l+1);
            r++;
        }

        return max_len;
    }
};

int main() {
    freopen("lc_340.inp","r",stdin);
    freopen("lc_340.out","w",stdout);
    Solution aws;
    string st;
    int k;
    scanf("%d\n",&k);
    getline(cin,st);
    cout<<aws.lengthOfLongestSubstringTwoDistinct(st,k);

    return 0;
}
