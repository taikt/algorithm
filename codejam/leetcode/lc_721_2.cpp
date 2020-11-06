/*
    https://leetcode.com/problems/accounts-merge/

    Input:
    accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnnybravo@mail.com"], ["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
    Output: [["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  ["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]
*/

// union_find
//
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;i++)

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int> emailId;
        unordered_map<int,set<string>> m;
        unordered_map<string,string> owner;
        vector<vector<string>> res;
        vector<int> parent(100,-1);
        //vector<int> parent(accounts.size(),0);
        int id=0;

        for(auto account: accounts) {
            // account: {john,a,b,c}
            FOR(i,1,account.size()) {
                if (emailId.find(account[i]) == emailId.end()) {
                    emailId[account[i]]=id;
                    parent[id] = id;
                    id++;
                }
                int x=findParent(emailId[account[1]],parent);
                int y=findParent(emailId[account[i]],parent);
                if (x!=y) parent[y]=x;

            }
        }

        for(auto account: accounts) {
            FOR(i,1,account.size()) {
                owner[account[i]]=account[0];
                int x=findParent(emailId[account[i]],parent);
                m[x].insert(account[i]);
            }
        }
        // m[1]->{a,b,c}
        // m[2] -> {x,y}
        for (auto a:m) {
            vector<string> v(a.second.begin(),a.second.end());
            if (v.size() != 0) {
                v.insert(v.begin(),owner[v[0]]);
                res.push_back(v);
            }
        }

        return res;
    }

    int findParent(int x, vector<int>& parent) {
        return (parent[x]==x)? x:(parent[x]=findParent(parent[x],parent));
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
