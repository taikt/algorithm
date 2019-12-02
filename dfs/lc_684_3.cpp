/*
    Input: [[1,2], [1,3], [2,3]]
    Output: [2,3]
    O(n^2)
*/
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;i++)

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> res={};
        int n=edges.size();

        vector<vector<int>> g(n,vector<int>()); // su dung 2-D vecto luu canh
        for(auto a:edges) {
            // su dung dfs de kiem tra do thi co chu trinh hay khong
            cout<<"check edge:["<<a[0]<<","<<a[1]<<"]\n";
            vector<bool> visited(n,false);
            g[a[0]].push_back(a[1]);
            g[a[1]].push_back(a[0]);

            cout<<a[0]<<a[1]<<"\n";

            if (dfsCheckCycle(a[1],g,-1,visited)) {
                return a;
            }

        }
        return res;
    }

    bool dfsCheckCycle(int cur,vector<vector<int>>& m,int pre,vector<bool>& visited) {
        if (visited[cur]) return true;
        visited[cur] = true;
        cout<<"cur="<<cur<<"\n";
        for (auto x:m[cur]) {
            if (x!= pre) {
                if (dfsCheckCycle(x,m,cur,visited)) return true;
            }
        }
        return false;
    }
};

int main() {
    freopen("lc_684.inp","r",stdin);
    freopen("lc_684.out","w",stdout);

    int n,m,a,b,c;

    scanf("%d %d\n",&n,&m);
    vector<vector<int>> edges(n);
    FOR(i,0,n) {
        scanf("%d %d\n",&a,&b);
        edges[i].push_back(a);
        edges[i].push_back(b);
    }

    Solution aws;
    vector<int> out= aws.findRedundantConnection(edges);
    cout<<"redundant edge:"<<out[0]<<out[1];

    return 0;
}
