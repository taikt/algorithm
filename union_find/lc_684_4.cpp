/*
    https://github.com/grandyang/leetcode/issues/684
    O(n)
*/
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;i++)

class Solution {
public:
    vector<int> findRedundantConnection(int n, vector<vector<int>>& edges) {
        vector<int> root(n,-1);

        for(auto a:edges) {
            int x=findSet(root,a[0]);
            int y=findSet(root,a[1]);
            if (x==y) return a;
            root[x] = y;
        }
        FOR(i,0,n)
            cout<<"i:"<<i<<","<<root[i]<<"\n";

        return {};
    }

    int findSet(vector<int>& root,int i) {
        return (root[i]==-1)? i : (root[i]=findSet(root,root[i]));
    }
};

int main() {
    Solution anw;
    freopen("lc_684.inp","r",stdin);
    freopen("lc_684.out","w",stdout);
    // n dinh, m canh
    int n,m,a,b;
    scanf("%d %d\n",&n,&m);
    vector<vector<int>> edges(m);
    FOR(i,0,m) {
        scanf("%d %d\n",&a,&b);
        edges[i].push_back(a);
        edges[i].push_back(b);
    }

    vector<int> out=anw.findRedundantConnection(n,edges);
    cout<<"["<<out[0]<<","<<out[1]<<"]\n";

    return 0;
}
