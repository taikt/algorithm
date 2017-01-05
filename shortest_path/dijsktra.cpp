// 22.12.2016, Tai<taitrananhvn@gmail.com>

// Tim khoang cach ngan nhat tu dinh nguon S toi tat ca
// cac dinh tren mot do thi trong so co huong

// Dijsktra algorithm
// Trong cac dinh chua tham(chua thuoc Shortest Path Tree), chon 1 dinh U co khoang cach
// tu S nho nhat (Khoi tao, dinh U chinh la S) (==> su dung cau truc du lieu MinHeap - priority_queue O(logn))
// Danh dau dinh U nay vao Shortest Path Tree
// Xet cac dinh ke V voi U, update khoang cach nho nhat tu S toi V neu thoa man dieu kien sau
// dist(V) > dist(U) + weight(U,V)
// Lap lai qua trinh tren cho den khi moi dinh deu thuoc SPT 

// Ref
// http://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/
// https://visualgo.net/sssp

#include <cstdio>
#include <queue>
using namespace std;
#define INF 10000 

int main() {
	//read input
	/*
	/ Graph in Figure 4.17
	  5 7 2 // V,E,Source
	  2 1 2 // (v1,v2)=W
	  2 3 7
	  2 0 6
	  1 3 3
	  1 4 6
	  3 4 5
	  0 4 1

	*/
	int V, E, S;
	int u,v,w;

	freopen("input.txt","r", stdin);
	scanf("%d %d %d",&V,&E,&S);
	vector< vector<pair<int,int> > > AdjList;

	AdjList.assign(V, vector<pair<int,int> >());

	for (int i = 0; i<E; i++) {
		scanf("%d %d %d",&u,&v,&w);
		AdjList[u].push_back(make_pair(v,w));
	}

	// Dijsktra
	// priority queue store like (<10,2>, <14,6>, <w,v>), w=dist(S,v)

	priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
	pq.push(pair<int,int>(0,S));

	vector<int> dist;
	dist.assign(V,INF); dist[S] = 0;
	while (!pq.empty()) {
		pair<int,int> min_item = pq.top(); pq.pop();
		int w= min_item.first, u = min_item.second;

		if (w > dist[u]) continue;

		// kiem tra cac dinh ke voi U
		for (int i=0; i < AdjList[u].size(); i++) {
			pair<int,int> v = AdjList[u][i];
			if (dist[v.first] > dist[u] + v.second) {
				dist[v.first] = dist[u] + v.second;
				pq.push(pair<int,int>(dist[v.first],v.first));
			}
		}
		
	}

	// Ket qua cuoi cung khoang cach ngan nhat toi cac dinh
	for (int i = 0; i<V; i++)
		printf("SSP(%d,%d)=%d\n",S,i, dist[i]);

	return 0;
}