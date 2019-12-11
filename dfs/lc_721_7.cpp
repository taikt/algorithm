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
        unordered_map<string,set<int>> emailId;

        int n=accounts.size();
        vector<bool> visited(n,false);
        vector<vector<string>> res;
        FOR(i,0,n) {
            FOR(j,1,accounts[i].size()) {
                emailId[accounts[i][j]].insert(i);
            }
        }

        FOR(i,0,n) {
            if (!visited[i]) {
                unordered_set<string> temp; // use set to avoid insert duplicated emails
                // if use vector, it need use find() to check duplicated email first, as result, make complexity n*n
                vector<string> out{accounts[i][0]};
                visitDFS(i,accounts,temp,visited,emailId);

                out.insert(out.end(),temp.begin(),temp.end());
                sort(out.begin()+1,out.end());

                res.push_back(out);
            }
        }

        return res;
    }

    void visitDFS(int i, vector<vector<string>>& accounts, unordered_set<string>& temp, vector<bool>& visited, unordered_map<string,set<int>>& emailId) {
        visited[i] = true;
        temp.insert(accounts[i].begin()+1,accounts[i].end());
        FOR(j,0,accounts[i].size()) {
            set<int> groupSet=emailId[accounts[i][j]];
            for (auto x: groupSet) {
                if (!visited[x]) visitDFS(x,accounts,temp,visited,emailId);
            }

        }
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
