/*
https://leetcode.com/articles/longest-substring-with-at-most-two-distinct-charac/
*/

// sliding-window


#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int i=0,l=0,r=0,max_len = 0;
        int n = s.length();
        if (n==0) return 0;
        unordered_map<char,int> m;
        while (r<n) {
            m[s[r]]++;
            // neu co nhieu hon 2 phan tu, xoa phan tu left most
            // i.e "eeetc" => "tc"
            while (m.size()>2 && r>=l) {
                m[s[l]]--;
                if(m[s[l]]==0) m.erase(s[l]);
                l++;
            }

            max_len = max(max_len,r-l+1);
            //cout<<max_len<<"\n";
            r++;
        }

        return max_len;
    }
};

int main() {
    freopen("lc_159.inp","r",stdin);
    freopen("lc_159.out","w",stdout);
    Solution aws;
    string st;
    getline(cin,st);
    cout<<aws.lengthOfLongestSubstringTwoDistinct(st);

    return 0;
}
