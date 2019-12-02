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
    //input is 1-D vector with pair
    bool validTree(int n, vector<pair<int,int>>& edges) {
        queue<int> q;
        q.push(0);
        unordered_set<int> s({0});
        vector<unordered_set<int>> g(n,unordered_set<int>());
        for (auto a:edges) {
            cout<<"a.first="<<a.first<<",a.second="<<a.second<<"\n";

            g[a.first].insert(a.second);
            g[a.second].insert(a.first);
        }
        int t=-1;
        while (!q.empty()) {
            t = q.front(); q.pop();
            for(auto v:g[t]) {
                if (s.count(v)) return false;
                else {
                    q.push(v);
                    s.insert(v);
                    // t is parent of v
                    g[v].erase(t); // khong tham lai dinh t tu dinh v
                    // erase, insert in unordered_set: O(1) on average
                }
            }
        }
        // return true; // neu return true, chi kiem tra do thi co chu trinh
        cout<<"size of s="<<s.size()<<"\n";
        return (s.size()==n);// kiem tra do thi co ket noi
    }
};

int main() {
    freopen("lc_261.inp","r",stdin);
    freopen("lc_261.out","w",stdout);

    //n: so dinh
    //m: so canh
    int m,n,x,y;
    scanf("%d %d\n",&n,&m);
    vector<pair<int,int>> edges; //edges(m) ==> wrong

    FOR(i,0,m) {
        scanf("%d %d\n",&x,&y);
        edges.push_back(make_pair(x,y));
    }

    Solution anw;
    if (anw.validTree(n,edges)) cout<<"true";
    else cout<<"false";

    return 0;
}
