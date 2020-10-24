// detect cycle in graph
// https://www.geeksforgeeks.org/detect-cycle-in-a-directed-graph-using-bfs/
// https://www.geeksforgeeks.org/detect-cycle-in-an-undirected-graph-using-bfs/
// https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/

#include <vector>
#include <queue>
#include <cstdio>
using namespace std;

class Graph {
     public:
         Graph(int V):V(V) {
             AdjList.assign(V,vector<pair<int,int> >());
             visited.assign(V,0);
             in_degree.assign(V,0);
             //topo_order.assign(V,0);
         }

         void dfs(int u);
         bool isCyclic(int u);
         bool checkCycle();
         void addEdge(int u, int v, int w);
         void bfs(int u);
         void printTopoOrder();
         void printInDegree();
         void reState() {
             visited.assign(V,0);
             // clear queue
             queue<int> temp;
             swap(q,temp);
         }

     private:
         int V;
         vector<vector<pair<int,int> > > AdjList;
         vector<int> visited;
         vector<int> in_degree;
         vector<int> topo_order; //topological order
         queue<int> q;
};

void Graph::addEdge(int u, int v, int w) {
    AdjList[u].push_back(make_pair(v,w));
    in_degree[v]++;
}

void Graph::bfs(int u) {
    q.push(u); visited[u] = 1;

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
}

// print topological ordering if graph is not cyclic
void Graph::printTopoOrder() {
    printf("topological ordering\n");
    for (int i=0; i<=topo_order.size()-1; i++) {
        printf("%d ", topo_order[i]);
    }
    printf("\n");
}

void Graph::printInDegree() {
    printf("In-degree at each vertice\n");
    // In-degree of a vetice is number of edges incomming that vertice
    // if graph has topological order, in-degree of every vertice is zero.
    // otherwise, it is cyclic.
    for (int i=0; i<V; i++) {
        printf("%d -> [%d], ",i,in_degree[i]);
    }
    printf("\n");
}

bool Graph::checkCycle() {
    reState();
    int cnt = 0;
    for (int i=0; i<V; i++) {
        if (in_degree[i] == 0) q.push(i);
    }

	while (!q.empty()) {
		int u = q.front(); q.pop();
        topo_order.push_back(u);
        cnt++;
		printf("visit %d\n",u);
		for (int i = 0; i< AdjList[u].size(); i++) {
			pair<int,int> item = AdjList[u][i];
			int v = item.first;
            if (--in_degree[v] == 0) q.push(v);
		}
	}
    if (cnt != V) return true;
    else return false;
}

int main() {
    int V,E;
/*
8 8
0 1 1
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

    Graph gr(V);

	for (int i=0; i< E;i++) {
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
	    gr.addEdge(u,v,w);
	}

    // bfs from vertice 0
    gr.bfs(0);
    printf("\ncheck cycle\n");
	if (gr.checkCycle()) {
        printf("graph is cyclic\n");
        gr.printInDegree();
    }
    else {
        printf("graph is not cyclic\n");
        gr.printTopoOrder();
        gr.printInDegree();
    }

	return 0;
}
