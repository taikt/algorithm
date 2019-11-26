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
					int x = findSet(root,i);
					int y = findSet(root,j);
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

	int findSet(vector<int>& root, int i) {
		while (i != root[i]) {
			root[i] = root[root[i]];
			i = root[i];
		}
		return i;
	}

};

int main() {
	vector<vector<int>> v={
		{1,1,0},
		{1,1,0},
		{0,0,1}
	};

	Solution anw;
	printf("%d\n",anw.findCircleNum(v));


	return 0;
}


