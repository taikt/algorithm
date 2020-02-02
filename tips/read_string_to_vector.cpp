#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("read_string_to_vector.inp","r",stdin);
    freopen("read_string_to_vector.out","w",stdout);
    vector<int> nums;
    vector<string> strs;
    string st;

    // read nums
    getline(cin,st);
    stringstream str(st);
    int t;
    while(str>>t)
        nums.push_back(t);

    for (auto a: nums) {
        cout<<a<<" ";
    }
    cout<<"\n";

    // read strings
    getline(cin,st);
    stringstream str2(st);
    string s;
    while(str2>>s)
        strs.push_back(s);

    for (auto a: strs) {
        cout<<a<<" ";
    }

    return 0;
}
