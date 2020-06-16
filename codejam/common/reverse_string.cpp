/*
    dao nguoc string:
    "abc" => "cba"

    Phuong phap: two pointers

    TODO
    phuong phap 2: su dung std::reverse in c++
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    void reverseString(vector<char>& s) {
        int low=0;
        int high=s.size()-1;
        while(low<high)
        {
            char temp=s[low];
            s[low]=s[high];
            s[high]=temp;
            low++;
            high--;
        }
    }
};

int main() {
    //freopen("lc_190.inp","r",stdin);
    //freopen("lc_190.out","w",stdout);
    string s; //="input";
    getline(cin,s);
    vector<char> v(s.begin(),s.end());

    Solution su;
    su.reverseString(v);
    for (auto c:v)
        cout<<c;

    return 0;
}
