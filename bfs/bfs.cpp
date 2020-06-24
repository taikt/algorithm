// 24.12.2016, Tai<taitrananhvn@gmail.com>

// Breadth-First Search
// https://visualgo.net/dfsbfs

#include <vector>
#include <queue>
#include <cstdio>
using namespace std;

int V,E;
vector<vector<pair<int,int> > > AdjList;
vector<int> visited;
queue<int> q;

int main() {
	// Doc input
	// Do thi co huong, trong so cac canh = 1,
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
		// AdjList[0] = {(1,1), (2,1)}
		// AdjList[1] = {(2,1), (3,1)}
		// AdjList[2] = {(3,1), (5,1)}
		// AdjList[3] = {(4,1)}
		// AdjList[7] = {(6,1)}
	}

	// Bat dau BFS tai 1 dinh bat ky
	q.push(0); visited[0] = 1;

	while (!q.empty()) {
		int u = q.front(); q.pop();
		printf("visit %d\n",u);
		for (int i = 0; i< AdjList[u].size(); i++) {
			pair<int,int> item = AdjList[u][i];
			int v = item.first;
			if (!visited[v]) {
				q.push(v); visited[v] = 1;
			}
		}
	}


	return 0;
}
