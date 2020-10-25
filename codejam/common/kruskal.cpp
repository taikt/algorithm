// 22.12.2016, Tai<taitrananhvn@gmail.com>

// Kruskal algorithm for finding minimum spanning tree in a weighted undirected graph
// this implementation uses Union-Find Disjoint Set for its data structure
// https://visualgo.net/mst

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class UnionFind {
private:
	int numSets; // number of disjoint sets
	// p: parent of tree node
	// setSize: size of a disjoint set
	// rank: rank of tree node ~ height of node initially
	vector<int> rank, p, setSize; 

public:
	UnionFind(int V) {
		numSets = V; // V disjoint sets initially
		rank.assign(V,0); 
		p.assign(V,0);
		setSize.assign(V,1);
		for (int i=0; i<V; i++) p[i] = i;
	}

	bool isSameSet(int i, int j) {
		return (findSet(i) == findSet(j));
	}

	int findSet(int i) {
		return ((p[i] == i) ? i : (p[i] = findSet(p[i]))); // path-compression also
	}

	void unionSet(int i, int j) {
		if (!isSameSet(i,j)) {
			numSets--;
			int x = findSet(i); 
			int y = findSet(j);
			if (rank[x] > rank[y]) {
				p[y] = x;
				setSize[x] += setSize[y];
			} else {
				p[x] = y;
				setSize[y] += setSize[x];
				if (rank[x] == rank[y]) rank[y]++;	
			}
		}
	}

	int sizeofSet(int i) {
		return setSize[findSet(i)];
	}

	int numDisjointSets() {
		return numSets;
	}
};

int main() {
	/*
	  // Graph in Figure 4.10 in CP book, list of weighted edges
	  
	  5 7
	  0 1 4
	  0 2 4
	  0 3 6
	  0 4 6
	  1 2 2
	  2 3 8
	  3 4 9
	*/
	int N,E;
	int u,v,w;

	freopen("input.txt","r", stdin);
	scanf("%d %d",&N,&E);
    
    // list of edges
    // edge(3), <0,2>
    // edge(1), <2,3>
    // edge(5), <0,3>
    //vector<pair<int, pair<int,int>>> EdgeList;

    // list of vertices
    // v(0) -> v(2), w=3
    // v(0) -> v(3), w=5
    // v(2) -> v(3), w=1
    // vector< vector< pair<int,int> > > AdjList;
    
    vector<pair<int,pair<int,int> > > EdgeList; // vector<pair<int,ii> >
    
    // https://stackoverflow.com/questions/25108854/initializing-the-size-of-a-c-vector/25108894
    //vector<vector<pair<int,int> > > AdjList(N);
    vector< vector<pair<int,int> > > AdjList(N,vector<pair<int,int>>());
    //AdjList.assign(N, vector<pair<int,int> >());

    for (int i = 0; i<E; i++) {
    	scanf("%d %d %d",&u,&v,&w);
    	EdgeList.push_back(make_pair(w, pair<int,int>(u,v)));

    	AdjList[u].push_back(make_pair(v,w));
    	AdjList[v].push_back(make_pair(u,w));
    }

    printf("EdgeList\n");
    for(vector<pair<int, pair<int,int> > >::iterator it = EdgeList.begin(); it != EdgeList.end(); it++) {
    	printf("w=%d v1=%d v2=%d\n", (*it).first, (*it).second.first, (*it).second.second);
    }

    // sorting EdgeList in ascending order
    sort(EdgeList.begin(), EdgeList.end());

    // Kruskal
    // sap xep cac canh theo thu tu tang dan trong so
    // lay canh nho nhat de gan vao MST neu thoa man dk sau:
    // khi them canh vao MST khong tao ra chu trinh.
    // lap lai qua trinh tren
    // note: kiem tra chu trinh bang viec xet 2 dinh cua canh
    // co thuoc cung 1 tap disjoint hay khong 
    int min_cost = 0;
    UnionFind UF(N);
    for (int i = 0; i<E; i++) {
    	pair<int, pair<int,int> > edge = EdgeList[i];
    	if (!UF.isSameSet(edge.second.first, edge.second.second)) {
    		min_cost += edge.first;
    		UF.unionSet(edge.second.first, edge.second.second);
    	}
    }

    printf("weight of MST=%d\n",min_cost);

    return 0;
}
