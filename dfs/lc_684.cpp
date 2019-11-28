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
        //unordered_map<int, unordered_set<int>> m; // keep tracking a map between each vertice and adjacent vertices
                                                  // of resulting tree
        /*
            m: {0} --> {1,2,3}
               {2} --> {4,5,3}
        */

        for(auto a:edges) {
            //if (check_cycle(a,m)) {
            //    return a;
            //}
            //count<< a[0] <<"\n";
            printf("%d %d\n",a[0],a[1]);

        }
        return res;
    }
};

int main() {
    freopen("lc_684.inp","r",stdin);
    freopen("lc_684.out","w",stdout);
    vector<vector<int>> edges={
        {0,1},
        {0,2}
        };
    #if 0
    int i,n,m,a,b;
    scanf("%d %d\n",&n,&m);
    FOR(i,0,n) {
        scanf("%d %d\n",&a,&b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    #endif
    Solution aws;
    vector<int> out= aws.findRedundantConnection(edges);

    return 0;
}
