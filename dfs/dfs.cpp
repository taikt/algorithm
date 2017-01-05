// 24.12.2016, Tai<taitrananhvn@gmail.com>

// Depth-First Search
// https://visualgo.net/dfsbfs

#include <vector>
#include <cstdio>
using namespace std;

int V,E;
vector<vector<pair<int,int> > > AdjList;
vector<int> visited;

void dfs(int u) {
	// danh dau tham dinh v
	visited[u] = 1; printf("visit %d\n",u);
	for (int i=0; i< AdjList[u].size(); i++) {
		pair<int,int> item = AdjList[u][i];
		int v = item.first;
		if (!visited[v]) dfs(v);
	}		
}

int main() {
	// Doc input
	// do thi co huong, trong so cac canh = 1, 
	// https://visualgo.net/dfsbfs, CP3 4.4. DAG
	/* 
	8 8 // V,E
	0 1 1 // dist(u,v) = 1
	0 2 1
	1 2 1
	1 3 1
	2 3 1
	2 5 1
	3 4 1
	7 6 1
	*/
	

	freopen("input.txt","r",stdin);
	scanf("%d %d",&V,&E);
	AdjList.assign(V,vector<pair<int,int> >());
	visited.assign(V,0);

	for (int i=0; i< E;i++) {
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		AdjList[u].push_back(make_pair(v,w));
	}

	// bat dau DFS tu 1 dinh bat ky
	dfs(0);

	return 0;
}