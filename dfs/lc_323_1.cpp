/*
	input: [[0, 1], [1, 2], [3, 4]]
	output: 2

*/
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	int countComponents(int n, vector<pair<int, int>>& edges) {
		int res=0;
		pair<int,int> a;
		vector<vector<int>> g(n); //need init size before using push_back, othewises, crash happends
		// https://www.techiedelight.com/initialize-two-dimensional-vector-cpp/
		// initiate a vector with n objects of vector<int> type
		// g[0], g[1], .. g[9], ..., g[n-1]
		vector<bool> visited(n,false);
		for (auto a : edges) {
			//printf("[%d,%d] ",a.first,a.second);
			g[a.first].push_back(a.second); 
			g[a.second].push_back(a.first);
		}
		// {{0,5},{2,9},{8,0}};
		// printf("%d %d\n",g[0][0],g[0][1]); //5,8
		// g[0] -> {5,8}
		// g[1] -> {}
		// g[2] -> [9]
		// g[3],g[4] -> {}
		// g[5] -> {0}
		// g[6],g[7] -> {}
		// g[8] -> 0

		for (int i=0; i<n; i++) {
			if (!visited[i]) {
				dfs(g,i,visited); // tham tu dinh i
				res++;
			}
		}

		return res;
	}

	void dfs(vector<vector<int>>& g, int i, vector<bool>& visited) {
		visited[i] = true;
		// tham tiep cac dinh cung canh voi i, tap g[i] chua cac dinh cung canh voi i
		for (int j=0; j<g[i].size(); j++) {
			if (!visited[g[i][j]]) dfs(g,g[i][j],visited);
		}
	}

	void dfs2(vector<vector<int>>& g, int i, vector<bool>& visited) {
		if (visited[i]) return;
        visited[i] = true;
        for (int j = 0; j < g[i].size(); ++j) {
            dfs(g, g[i][j], visited);
        }
	}
};

int main() {
	vector<pair<int,int>> edges={{0,1},{1,2},{3,4}};
	Solution anw;
	printf("%d\n", anw.countComponents(5,edges));

	return 0;
}