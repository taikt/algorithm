/*
	https://leetcode.com/problems/number-of-islands/

	input:
	11000
	11000
	00100
	00011

	output: 3
*/
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

// BFS
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
    	int m,n,res=0;
    	m = grid.size(); n = grid[0].size();
    	printf("%d %d\n",m,n);
    	vector<vector<bool>> visited(m,vector<bool>(n)); //all elements are false
        vector<int> xdiv={0,-1,1,0}; //v={} or v{} both ok
        vector<int> ydiv{1,0,0,-1};
        for (int i=0; i<m; i++) {
        	for (int j=0; j<n; j++) {
        		if ((grid[i][j] == '0') || visited[i][j]) continue;
        		res++;
                queue<int> q{{i*n+j}}; // queue<int> q({i*n+j});--> ok
                visited[i][j] =true;
                while (!q.empty()) {
                    int t=q.front(); q.pop();
                    for (int k=0; k<4;k++) {
                        int x=t/n+xdiv[k], y=t%n+ ydiv[k];
                        if (x<0 || x>=m || y<0 || y>=n || visited[x][y] || grid[x][y]=='0') continue;
                        visited[x][y] = true;
                        q.push(x*n+y);
                    }
                }
        	}
        	//printf("\n");
        }

        return res;
    }

};

// dfs
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
    	int m,n,res=0;
    	m = grid.size(); n = grid[0].size();
    	printf("%d %d\n",m,n);
    	vector<vector<bool>> visited(m,vector<bool>(n)); //all elements are false

        for (int i=0; i<m; i++) {
        	for (int j=0; j<n; j++) {
        		if ((grid[i][j] == '0') || visited[i][j]) continue;
        		visitDFS(grid,visited,i,j);
        		res++;
        	}
        	//printf("\n");
        }
        return res;
    }

    void visitDFS(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j) {
    	visited[i][j] = true;
    	int m=grid.size(), n=grid[0].size();
    	if (i<m-1 && grid[i+1][j]=='1' && !visited[i+1][j]) visitDFS(grid,visited, i+1,j);
    	if (i>0 && grid[i-1][j]=='1' && !visited[i-1][j]) visitDFS(grid,visited, i-1,j);
    	if (j<n-1 && grid[i][j+1]=='1' && !visited[i][j+1]) visitDFS(grid,visited, i,j+1);
    	if (j>0 && grid[i][j-1]=='1' && !visited[i][j-1]) visitDFS(grid,visited, i,j-1);
    }
#if 0
    void helper(vector<vector<char>>& grid,vector<vector<bool>>& visited, int x, int y) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == '0' || visited[x][y]) return;
        visited[x][y] = true;
        helper(grid, visited, x - 1, y);
        helper(grid, visited, x + 1, y);
        helper(grid, visited, x, y - 1);
        helper(grid, visited, x, y + 1);
    }
#endif
};

int main() {
	Solution anw;
	vector<vector<char>> grid={
		{'1','1','0','0','0'},
		{'1','1','0','0','0'},
		{'0','0','1','0','0'},
		{'0','0','0','1','1'}
	};

	printf("%d\n", anw.numIslands(grid));

	return 0;
}
