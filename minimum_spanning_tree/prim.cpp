// 22.12.2016, Tai<taitrananhvn@gmail.com>

// Prim algorithm for finding a Minimum Spanning Tree(MST) in a weighted undirected graph

// MST khoi tao voi dinh 0
// Tim cac canh ke voi 0, day cac canh ke vao priority queue (MinHeap)
// * Remove canh co trong so nho nhat tu priority queue - e
// Kiem tra dinh v(gan voi canh e) co thuoc MST hay chua
// Neu v chua thuoc MST, thi danh dau v va canh e vao MST
// Nguoc lai, bo qua canh e va dinh v
// Neu (v,e) da duoc danh dau vao MST, xet cac canh ke voi v, va day 
// nhung canh nay vao priority queue (neu dinh gan voi canh do chua thuoc MST)
// De qui * cho toi khi tat ca cach dinh cua cay deu thuoc MST,
// Cay MST se co trong so nho nhat

// Ref
// https://visualgo.net/mst
// http://www.geeksforgeeks.org/greedy-algorithms-set-5-prims-minimum-spanning-tree-mst-2/

#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int V, E;
int u,v,w;
vector<vector<pair<int,int> > > AdjList; // Luu cac dinh va canh ke cua do thi
vector<int> taken; // luu cac dinh thuoc MST

// tao MinHeap priorty queue dang {(w,v)} 
priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
// de tao Maxheap priority queue
// khai bao priority_queue<pair<int,int> >

// Danh dau dinh V vao MST
// add cac canh ke cua V vao priority queue neu dinh gan voi canh chua thuoc MST
void process(int v) {
	taken[v] = 1;
	for (int i=0; i < AdjList[v].size(); i++) {
		pair<int,int> item = AdjList[v][i];
		int u = item.first, w = item.second;
		if (!taken[u]) {
			pq.push(make_pair(w,u));
		}
	}
}

int main() {

	// Doc input
	/*
	  // Do thi hinh 4.10, danh sach cac canh co trong so
	  5 7
	  0 1 4
	  0 2 4
	  0 3 6
	  0 4 6
	  1 2 2
	  2 3 8
	  3 4 9
	*/
	
	freopen("input.txt","r",stdin);
	scanf("%d %d",&V,&E);

	AdjList.assign(V,vector<pair<int,int> >());
	taken.assign(V,0); // moi dinh chua thuoc MST

	for (int i=0; i<E; i++) {
		scanf("%d %d %d",&u,&v,&w);
		AdjList[u].push_back(make_pair(v,w));
		AdjList[v].push_back(make_pair(u,w));
	}

	
	process(0); 
	
	int mst_cost = 0;
	while (!pq.empty()) {
		pair<int,int> edge = pq.top(); pq.pop();
		int v = edge.second, w= edge.first;

		if (!taken[v]) {
			mst_cost += w;
			process(v);
		}
	}

	printf("Weight of Minimum Spanning Tree(MST) = %d\n",mst_cost);

	return 0;
}