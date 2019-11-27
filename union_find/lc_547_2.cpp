/*
https://leetcode.com/problems/friend-circles/

https://www.geeksforgeeks.org/union-find/
O(n)

https://www.geeksforgeeks.org/union-find-algorithm-set-2-union-by-rank/
O(logn)


method: union-find use path compession(after find a given node'root, the root become parent of given node)
+ ranking (use rank at each node, node with larger height then get higher rank)
comlexity: O(logn)

input:
[[1,1,0],
 [1,1,0],
 [0,0,1]]

output: 2

*/

#include <cstdio>
using namespace std;
#include <vector>

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
		return res;

	}
	/*
	ie. i->j->k->l->O  (root[i]=k, root[k]=o)
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
	i.e i->j->k->l->o
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
	int findSet2(vector<int>& root, int i) {
		if (i == root[i]) return i;
		else {
			root[i] = findSet2(root,root[i]);
			return root[i];
		}
	}

};

int main() {
	vector<vector<int>> v={
		{1,1,0},
		{1,1,0},
		{0,0,1}
	};

	Solution anw;
	printf("number of circle friend: %d\n",anw.findCircleNum(v));


	return 0;
}


