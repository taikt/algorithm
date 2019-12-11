/*
    https://leetcode.com/problems/accounts-merge/

    Input:
    accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnnybravo@mail.com"], ["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
    Output: [["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  ["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]

*/
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
        vector<int> parent(100,-2); // crash on leetcode

        FOR(i,0,accounts.size()) {
            parent[i] = -1;
            FOR(j,1,accounts[i].size()) {
                if (emailId.find(accounts[i][j]) != emailId.end()) {
                    int x=findParent(emailId[accounts[i][j]],parent);
                    int y=findParent(i,parent);
                    //union
                    parent[x]=y;
                } else {
                    emailId[accounts[i][j]] = i;
                }
            }
        }

        // emailID
        // a -> 0
        // b -> 0
        // x -> 1
        int root;
        for(auto x:emailId) {
            root = findParent(x.second,parent);
            m[root].insert(x.first);
            //cout<<x.second<<","<<x.first<<"\n";
        }
        //m
        // {0} -> {a,b}
        // {1} -> {x}
        for (auto x:m) {
            vector<string> v(x.second.begin(), x.second.end());
            v.insert(v.begin(),accounts[x.first][0]);
            res.push_back(v);
        }

        return res;
    }

    int findParent(int x, vector<int>& parent) {
        return (parent[x]==-1)? x:(parent[x]=findParent(parent[x],parent));
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
