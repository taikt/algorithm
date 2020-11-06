/*
    https://leetcode.com/problems/graph-valid-tree/
    https://github.com/grandyang/leetcode/issues/261

    method: Union-Find to check cycling of undirected graph
    valid tree if: not having cycle and connected graph

    Input: n = 5, and edges = [[0,1], [0,2], [0,3], [1,4]]
    Output: true

*/

// union_find
//
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a; i<b;i++)

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
       vector<int> root(n,-1);
       int res = 0;
       for(auto a: edges) {
            cout<<"a[0]="<<a[0]<<",a[1]="<<a[1]<<"\n";
            int x=findSet(root,a[0]);
            int y=findSet(root,a[1]);
            if (x==y) return false; // graph co chu trinh
            root[x]=y;
       }

       FOR(i,0,n) {
           cout<<"i="<<i<<":"<<root[i]<<"\n";
           if (root[i] == -1) ++res;
       }
       if (res = 1) return true; // graph ket noi
       else return false;
    }
    int findSet(vector<int>& root, int i) {
        return (root[i] == -1) ? i : (root[i]=findSet(root,root[i]));
    }
    // use ranking
    bool validTree2(int n, vector<vector<int>>& edges) {
       vector<int> root(n,-1);
       vector<int> rank(n,1);
       int res = 0;
       for(auto a: edges) {
            cout<<"a[0]="<<a[0]<<",a[1]="<<a[1]<<"\n";
            int x=findSet(root,a[0]);
            int y=findSet(root,a[1]);
            if (x==y) return false; // graph co chu trinh
            // su dung ranking
            if (rank[x]>rank[y]) root[y]=x;
            else {
                root[x]=y;
                if (rank[x]==rank[y]) rank[y]++;
            }
       }

       FOR(i,0,n) {
           cout<<"i="<<i<<":"<<root[i]<<"\n";
           if (root[i] == -1) ++res;
       }
       if (res = 1) return true; // graph ket noi
       else return false;
    }

};

int main() {
    freopen("lc_261.inp","r",stdin);
    freopen("lc_261.out","w",stdout);
    //n: so dinh
    //m: so canh
    int m,n,x,y;
    scanf("%d %d\n",&n,&m);
    vector<vector<int>> edges(m);
    FOR(i,0,m) {
        scanf("%d %d\n",&x,&y);
        edges[i].push_back(x);
        edges[i].push_back(y);
    }

    Solution anw;
    if (anw.validTree(n,edges)) cout<<"true";
    else cout<<"false";

    return 0;
}
