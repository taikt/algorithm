/*
https://leetcode.com/problems/friend-circles/

https://www.geeksforgeeks.org/union-find/
O(n)

https://www.geeksforgeeks.org/union-find-algorithm-set-2-union-by-rank/
O(logn)

method: union-find not use path compession+ ranking
comlexity: O(n)

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
		for (int i=0; i<n; i++) root[i] = i;
		int res=n;

		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				if (M[i][j]) {
					int x = findSet(root,i);
					int y = findSet(root,j);
					if (x!=y) {
						root[x] = y;
						res--;
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


