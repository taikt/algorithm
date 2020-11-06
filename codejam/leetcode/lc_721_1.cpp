/*
    https://leetcode.com/problems/accounts-merge/

    Input:
    accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnnybravo@mail.com"], ["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
    Output: [["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  ["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]

    Method:
    {john,a,b,c,d}, {john,b,x,y}
    initial unions: {a}->a,{b}->b,{c}->c, {d}->d, {x}->x, {y}->y
    united:
    root[b]->root[a]=a: {b}-> a
    root[c]-> root[a]=a: {b,c} -> a
    root[d]-> root[a]: {b,c,d} -> a
    root[x] -> root[b]=a: {b,c,d,x} ->a
    root[y] -> root[b]=a: {b,c,d,x,y} -> a

    General: root[v[i]] -> root[v[1]], i>=2, v[0]='name'
*/
#include <bits/stdc++.h>
using namespace std;
// union_find
//
#define FOR(i,a,b) for(int i=a;i<b;i++)

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,string> root;
        unordered_map<string,set<string>> m;
        unordered_map<string,string> owner;
        vector<vector<string>> res;

        for(auto account: accounts) {
            FOR(i,1,account.size()) {
                owner[account[i]] = account[0];
                root[account[i]] = account[i];
            }
        }

        for (auto account: accounts) {
            string x=findRoot(account[1],root);
            FOR(i,2,account.size()) {
                root[findRoot(account[i],root)] = x;
            }
        }

        for(auto account: accounts) {
            FOR(i,1,account.size()) {
                string t=findRoot(account[i],root);
                m[t].insert(account[i]);
            }
        }

        for (auto a: m) {
            vector<string> st(a.second.begin(),a.second.end());
            st.insert(st.begin(),owner[a.first]);
            res.push_back(st);
        }

        return res;

    }
    string findRoot(string x,unordered_map<string,string> & root) {
        return (x==root[x])? x: (root[x]=findRoot(root[x],root));
    }

};

int main() {
    Solution anw;
    int n=0;
    string st,word;

    freopen("lc_721.inp","r",stdin);
    freopen("lc_721.out","w",stdout);

    scanf("%d\n",&n);
    vector<vector<string>> accounts(n);
    FOR(i,0,n) {
        getline(cin,st);
        stringstream str(st);
        while (str>>word)
            accounts[i].push_back(word);
    }
    vector<vector<string>> out=anw.accountsMerge(accounts);

    for (auto a: out) {
        FOR(i,0,a.size())
            cout<<a[i]<<" ";
        cout<<"\n";
    }


    return 0;
}
