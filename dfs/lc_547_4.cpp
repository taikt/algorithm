/*
https://leetcode.com/problems/friend-circles/
https://leetcode.com/problems/friend-circles/solution/
https://github.com/grandyang/leetcode/issues/547

https://www.geeksforgeeks.org/union-find/
O(n)

https://www.geeksforgeeks.org/union-find-algorithm-set-2-union-by-rank/
O(logn)


method: dfs
time complex O(n^2), space complex O(n)

input:
[[1,1,0],
 [1,1,0],
 [0,0,1]]

output: 2

*/


#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;i++)


class Solution {
public:
	int findCircleNum(vector<vector<int>>& M) {
		int n= M.size();
		int res=0;
		vector<bool> visisted(n,false);
		FOR(i,0,n) {
            if (!visisted[i]) {
                dfs(i,visisted,M);
                res++;
            }
		}
		return res;
	}

	void dfs(int i, vector<bool>& visisted, vector<vector<int>>& M) {
	    int n=M.size();
	    FOR(j,0,n) {
            if (!visisted[j] && M[i][j]) {
                visisted[j]=true;
                dfs(j,visisted,M);
            }
	    }
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


