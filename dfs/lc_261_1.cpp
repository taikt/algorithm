/*
    https://leetcode.com/problems/graph-valid-tree/
    https://github.com/grandyang/leetcode/issues/261

    method: DFS
    valid tree if: not having cycle and connected graph

*/
#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=a; i<b; i++)

class Solution {
public:
    bool validTree(int n, vector<pair<int,int>>& edges) { //edges is given as 1-dimensional vector using pair
        vector<bool> visisted(n,false);
        vector<vector<int>> g(n,vector<int>());
        for (auto a:edges) {
            g[a.first].push_back(a.second);
            g[a.second].push_back(a.first);
        }

        if (dfs_cycle(0,visisted,g,-1)) return false; // check cycle
        FOR(i,0,n) {
            if (!visisted[i]) return false; // check connected graph
        }
        return true;
    }

    // return true if graph has cycle
    bool dfs_cycle(int i, vector<bool>& visited, vector<vector<int>>& edges, int pre) {
        int n=visited.size();
        if (visited[i]) return true;
        visited[i] = true;
        for (auto j: edges[i]) {
            if (j!=pre) {
                if (dfs_cycle(j,visited,edges,i)) return true;
            }
        }
        return false;
    }
};

int main() {
    freopen("lc_261.inp","r",stdin);
    freopen("lc_261.out","w",stdout);
    int n,a,b,m;

    scanf("%d %d\n",&n,&m);
    vector<pair<int,int>> edges(m);
    FOR(i,0,m) {
        scanf("%d %d\n",&a,&b);
        edges.push_back(make_pair(a,b));
    }
    Solution ans;
    if (ans.validTree(n,edges)) cout<<"true\n";
    else cout<<"false\n";

    return 0;
}
