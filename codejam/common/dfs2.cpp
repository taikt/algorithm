// 24.12.2016, Tai<taitrananhvn@gmail.com>

// Depth-First Search
// https://visualgo.net/dfsbfs

#include <vector>
#include <cstdio>
using namespace std;


class Graph {
    public:
        Graph(int V):V(V) {
	        AdjList.assign(V,vector<pair<int,int> >());
	        visited.assign(V,0);
	        restack.assign(V,0);
        }

        void dfs(int u);
        void addEdge(int u, int v, int w);

    private:
        int V;
        vector<vector<pair<int,int> > > AdjList;
        vector<int> visited;

};


void Graph::dfs(int u) {
	visited[u] = 1; printf("visit %d\n",u);
	for (int i=0; i< AdjList[u].size(); i++) {
		pair<int,int> item = AdjList[u][i];
		int v = item.first;
		if (!visited[v]) dfs(v);
	}		
}


void Graph::addEdge(int u, int v, int w) {
    AdjList[u].push_back(make_pair(v,w));
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
    int V,E;	

	freopen("input.txt","r",stdin);
	scanf("%d %d",&V,&E);
    
    Graph gr(V);

	for (int i=0; i< E;i++) {
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
        gr.addEdge(u,v,w);
	}

	// bat dau DFS tu 1 dinh bat ky
    printf("DFS from vertice 0\n");
	gr.dfs(0);
    printf("DFS end\n\n");
    

	return 0;
}
