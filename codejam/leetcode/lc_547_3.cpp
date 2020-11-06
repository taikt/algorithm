/*
https://leetcode.com/problems/friend-circles/
https://leetcode.com/problems/friend-circles/solution/

https://www.geeksforgeeks.org/union-find/
O(n)

https://www.geeksforgeeks.org/union-find-algorithm-set-2-union-by-rank/
O(logn)


method: union-find using path compression(after find a given node'root, the root become parent of given node)
+ ranking (use rank at each node, node with higher height then get higher rank)
Complexity: O(logn)

input:
[[1,1,0],
 [1,1,0],
 [0,0,1]]

output: 2

*/

#include <windows.h>
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;i++)


class Solution {
public:
	int findCircleNum(vector<vector<int>>& M) {
		int n= M.size();
		vector<int> parent(n,-1);
		vector<int> rank(n,0);
		int res=0;

		FOR(i,0,n) {
			FOR(j,0,n) {
				if (M[i][j] && i!=j) {
					int x = findSet(parent,i);
					int y = findSet(parent,j);
					if (x != y) {
                        //parent[x]=y; //union i,j to a group, not using rank
                        if (rank[x]>rank[y]) { //union by rank
                            parent[y] = x;
                        } else {
                            parent[x]=y;
                            if (rank[x]==rank[y]) rank[y]++;
                        }
					}
				}
			}
		}

		FOR(i,0,n) {
            if (parent[i]==-1) res++;
		}

		return res;
	}


	// path compression
	int findSet(vector<int>& parent, int i) {
	    #if 0
		if (i == root[i]) return i;
		else {
			root[i] = findSet2(root,root[i]);
			return root[i];
		}
		#endif // 0

		return (-1 == parent[i]) ? i : (parent[i]=findSet(parent,parent[i]));
	}

};

int main() {

    freopen("lc_547.inp","r",stdin);
    freopen("lc_547.out","w",stdout);
    int n;
    scanf("%d\n",&n);
    vector<vector<int>> v(n,vector<int>(n)); //without initialization, it crash
    for (int i=0; i<n;i++) {
        for (int j=0; j<n; j++) {
            scanf("%d",&v[i][j]);
        }
    }
	Solution anw;
	cout<<anw.findCircleNum(v);


	return 0;
}


