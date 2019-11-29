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
        unordered_map<int, unordered_set<int>> m; // keep tracking a map between each vertex and set of adjacent vertices of resulting tree
        /*
            m: {0} --> {1,2,3}
               {2} --> {4,5,3}
        */
        for(auto a:edges) {
            //if (check_cycle(a,m)) {
              //  return a;
            //}
            cout<<a[0]<<a[1]<<"\n";
            m[a[0]].insert(a[1]);
            m[a[1]].insert(a[0]);
        }

        for (auto a:m) {
            cout<<a.first<<"-->";
            for (auto x:a.second) {
                cout<<x<<" ";
            }
            cout<<"\n";
        }

        return res;
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

    return 0;
}
