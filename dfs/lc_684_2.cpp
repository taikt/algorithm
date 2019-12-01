/*
    Input: [[1,2], [1,3], [2,3]]
    Output: [2,3]

*/
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;i++)

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> res={};
        int n=edges.size();

        unordered_map<int, unordered_set<int>> m; // su dung map luu canh
        // keep tracking a map between each vertex and set of adjacent vertices of resulting tree
        /*
            m: {0} --> {1,2,3}
               {2} --> {4,5,3}
        */
        for(auto a:edges) {
            // su dung dfs de kiem tra do thi co chu trinh hay khong
            cout<<"check edge:["<<a[0]<<","<<a[1]<<"]\n";
            vector<bool> visited(n,false);
            cout<<a[0]<<a[1]<<"\n";
            m[a[0]].insert(a[1]);
            m[a[1]].insert(a[0]);
            if (dfsCheckCycle(a[1],m,-1,visited)) {
                return a;
            }

        }
#if 0
        for (auto a:m) {
            cout<<a.first<<"-->";
            for (auto x:a.second) {
                cout<<x<<" ";
            }
            cout<<"\n";
        }
#endif // 0
        return res;
    }

    bool dfsCheckCycle(int cur,unordered_map<int, unordered_set<int>>& m,int pre,vector<bool>& visited) {
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
    // m: so dinh, n: so canh
    scanf("%d %d\n",&n,&m); //m=n
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
