// 24.12.2016, Tai<taitrananhvn@gmail.com>

// Depth-First Search
// https://visualgo.net/dfsbfs
// https://www.geeksforgeeks.org/detect-cycle-undirected-graph/
// https://www.geeksforgeeks.org/detect-cycle-in-a-graph/
// https://www.geeksforgeeks.org/topological-sorting/

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
        bool isCyclic(int u);
        bool checkCycle();
        void addEdge(int u, int v, int w);
        void printTopoOrder();
        void reState() {
	        visited.assign(V,0);
	        restack.assign(V,0);
        }
        void clearTopoQueue();

    private:
        int V;
        vector<vector<pair<int,int> > > AdjList;
        vector<int> visited, restack, topo_order;
};

void Graph::dfs(int u) {
	visited[u] = 1; printf("visit %d\n",u);
	for (int i=0; i< AdjList[u].size(); i++) {
		pair<int,int> item = AdjList[u][i];
		int v = item.first;
		if (!visited[v]) dfs(v);
	}		
}

bool Graph::isCyclic(int u) {
	visited[u] = 1; printf("visit %d\n",u);
    restack[u] = 1;
	for (int i=0; i< AdjList[u].size(); i++) {
		pair<int,int> item = AdjList[u][i];
		int v = item.first;
		if (!visited[v]) {
            if (isCyclic(v)) return true;
        }
        if (restack[v]) return true;
	}

    restack[u] = 0;
    topo_order.push_back(u);
    return false;    
}

void Graph::clearTopoQueue() {
    topo_order.clear();
}
// print topological ordering if graph is not cyclic
void Graph::printTopoOrder() {
    for (int i=topo_order.size()-1; i>=0; i--) {
        printf("%d ", topo_order[i]);
    }
    printf("\n");
}


void Graph::addEdge(int u, int v, int w) {
    AdjList[u].push_back(make_pair(v,w));
}

bool Graph::checkCycle() {
    reState();
    for (int i=0; i<V; i++) {
        if (!visited[i] && isCyclic(i)) {
            return true;
        }
    }
    
    return false;
}

int main() {
    int V,E;	

	freopen("input.txt","r",stdin);
	scanf("%d %d",&V,&E);
    
    Graph gr(V);

	for (int i=0; i< E;i++) {
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
        gr.addEdge(u,v,w);
	}

    printf("DFS from vertice 0\n");
	gr.dfs(0);
    printf("DFS end\n\n");
    
    printf("check circlic\n");
    if (gr.checkCycle())  printf("have a circle\n");
        else {
            printf("no circle\n");
            printf("topological order\n");
            gr.printTopoOrder();
        }

	return 0;
}
