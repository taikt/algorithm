/*
    https://leetcode.com/problems/graph-valid-tree/
    https://github.com/grandyang/leetcode/issues/261

    method: DFS
    valid tree if: not having cycle and connected graph

    Input: n = 5, and edges = [[0,1], [0,2], [0,3], [1,4]]
    Output: true

*/
#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=a; i<b; i++)

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) { //edges is given as 2-dimensional vector
        vector<bool> visisted(n,false);

        if (dfs_cycle(0,visisted,edges,-1)) return false; // check cycle
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
    vector<vector<int>> edges(m,vector<int>());
    FOR(i,0,m) {
        scanf("%d %d\n",&a,&b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    Solution ans;
    if (ans.validTree(n,edges)) cout<<"true\n";
    else cout<<"false\n";

    return 0;
}
