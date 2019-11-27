/*
https://leetcode.com/problems/friend-circles/

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


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
	int findCircleNum(vector<vector<int>>& M) {
		int n= M.size();
		vector<int> root(n);
		vector<int> rank(n,0);
		for (int i=0; i<n; i++) root[i] = i;
		int res=n;

		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				if (M[i][j]) {
					int x = findSet2(root,i);
					int y = findSet2(root,j);
					if (x != y) {
                        if (rank[x] > rank[y]) {
                            root[y] = x;
                            res--;
                        } else { //rank[y] >= rank[x]
                            root[x] = y;
                            res--;
                            if (rank[y] == rank[x]) rank[y]++;
                        }
					}
				}
			}
		}
		return res;

	}
	/*
	ie. i->j->k->l->O  (result: root[i]=k, root[k]=o)
		1.
		root[i] = root[j] =k
		i = k;
		2.
		root[k] = root[l] = o;
		i = o;
		3.
		i= o; return o;
	*/
	int findSet1(vector<int>& root, int i) {
		while (i != root[i]) {
			root[i] = root[root[i]];
			i = root[i];
		}
		return i;
	}

	/*
	i.e i->j->k->l->o (result: root[i]=root[j]=root[k]=root[l]=root[o]=o)
		1. findSet2(i)
		root[i] = findset2(j); // backtrace: root[i] = o
		return findset2(j);
		2. findSet2(j)
		root[j] = findSet2(k); // backtrace: root[j] = o
		return findSet2(k);
		3. findSet2(k)
		root[k] = findSet2(l); // backtrace: root[k]=o
		return findSet2(l);
		4. findSet2(l)
		root[l] = findset2(o); // backtrace: root[l]=o;
		return findSet2(o);
		5.
		return o;
	*/
	// path compression
	int findSet2(vector<int>& root, int i) {
	    #if 0
		if (i == root[i]) return i;
		else {
			root[i] = findSet2(root,root[i]);
			return root[i];
		}
		#endif // 0

		return (i == root[i]) ? i : (root[i]=findSet2(root,root[i]));
	}

};

int main() {

    freopen("lc_547.inp","r",stdin);
    freopen("lc_547.out","w",stdout);
    int n,t;
    scanf("%d\n",&n);
    //cin>>n;
    vector<vector<int>> v(n,vector<int>(n)); //without initialization, it crash
    for (int i=0; i<n;i++) {
        for (int j=0; j<n; j++) {
            scanf("%d",&v[i][j]);
            //cin>>v[i][j];
            //printf("%d ",v[i][j]);
        }
        //printf("\n");
    }

	#if 0
	vector<vector<int>> v={
		{1,1,0},
		{1,1,0},
		{0,0,1}
	};
    #endif // 0
	Solution anw;
	printf("number of circle friend: %d\n",anw.findCircleNum(v));


	return 0;
}


