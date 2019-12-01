/*
    https://leetcode.com/problems/graph-valid-tree/
    https://github.com/grandyang/leetcode/issues/261

    method: BFS to check cycling of undirected graph
    valid tree if: not having cycle and connected graph

    Input: n = 5, and edges = [[0,1], [0,2], [0,3], [1,4]]
    Output: true

*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a; i<b;i++)

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        queue<int> q;
        q.push(0);
        vector<bool> visited(n,false);
        vector<int> pre(n,-1);
        int t=-1;
        while (!q.empty()) {
            t = q.front(); q.pop();
            visited[t]=true;
            for(auto v:edges[t]) {
                if (!visited[v]) {
                    q.push(v);
                    pre[v]=t;
                } else if (v!=pre[t]) // neu dinh v da duoc tham ma khong phai la parent cua t thi do thi co chu trinh
                return false;
            }
        }
        return true;
    }
};

int main() {
    freopen("lc_261.inp","r",stdin);
    freopen("lc_261.out","w",stdout);
    //m: so dinh
    //n: so canh
    int m,n,x,y;
    scanf("%d %d\n",&m,&n);
    vector<vector<int>> edges(m);
    FOR(i,0,n) {
        scanf("%d %d\n",&x,&y);
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    Solution anw;
    if (anw.validTree(m,edges)) cout<<"true";
    else cout<<"false";

    return 0;
}
