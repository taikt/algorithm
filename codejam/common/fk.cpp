// 24.12.2016, Tai<taitrananhvn@gmail.com>

// Ford Fulkerson algorithm
// https://visualgo.net/maxflow
/*
initMaxFlow
while there is an augmenting path
  find an augmenting path using DFS
  for each edge u->v in the path
    decrease capacity u->v by bottleneck
    increase capacity v->u by bottleneck
  increase maxflow by bottleneck
*/

#include <cstdio>
#include <algorithm> //min()
#include <vector>
#include <queue>
#include <cstring> //memset
using namespace std;

#define INF 10000
#define MAX_V 30

vector<int> visited,p;
int res[MAX_V][MAX_V];
int V, E, s, t, f;

void augment(int u, int minEd) {
	if (u == s) {
		f = minEd;
		return;
	} 
	else if (p[u] != -1) {
		augment(p[u],min(minEd,res[p[u]][u]));
		res[p[u]][u] -= f;
		res[u][p[u]] += f; 
	}
}

// DFS
void dfs(int u) {
	visited[u] = 1;
	if (u == t) return; // dung DFS neu duyet den dinh t
	for (int i=0; i<V; i++) 
		if (res[u][i] > 0 && !visited[i]) {
			p[i] = u;
			dfs(i);
		}
}

int main() {
	int u,v,w;

	freopen("input.txt","r",stdin);

	// Do thi trong so co huong CP3 4.26.1(s-lim), https://visualgo.net/maxflow
	/*
	5 7 0 4 // V E s t, tim luong cuc dai tu s toi t, tren do thi trong so co huong V dinh, E canh
	0 2 5 // weight(u,v) = w
	0 3 3
	1 4 7
	2 1 3
	2 3 3
	2 4 3
	3 1 5
	*/

	scanf("%d %d %d %d",&V, &E, &s,&t);
	memset(res,0, sizeof(res));

	for (int i=0; i<E; i++) {
		scanf("%d %d %d",&u,&v,&w);
		res[u][v] = w;
	}

	int mf = 0; //max flow
	while (1) {
		// Tim augmenting path bang DFS
		// f co gia tri bang canh co trong so nho nhat tren augmenting path
		f = 0;
		queue<int> q; //Tai moi buoc tim augmenting path, khoi tao queue la empty
		visited.assign(V,0); // Chua co dinh nao duoc tham
		p.assign(V,-1); // parent cua moi dinh la empty

		// DFS
		dfs(s);

		augment(t,INF); // duyet quay lui tu dinh t de tim f tren augmentin path, khoi tao f = INF
		
		if (f == 0) break; // Khong tim thay augmenting path nao nua

		mf += f;
	}

	printf("Maximum network flow from %d to %d= %d\n",s,t,mf);

	return 0;
}
