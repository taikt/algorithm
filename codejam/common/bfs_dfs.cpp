#include <bits/stdc++.h>
using namespace std;

int n=5;
vector<vector<int>> v(n+1, vector<int>());
vector<int> visited;
queue<int> q;

// O(V+E): V dinh, E canh
// https://www.quora.com/What-is-the-time-complexity-of-Breadth-First-Search-Traversal-of-a-graph
// neu thuc hien theo adjacent list, tai moi dinh, se travel cac canh lien ke
// tong canh la O(E)
// sau do visit chinh dinh lien ke, tong dinh la O(V)
// tong time visit la O(E) + O(V)
void bfs(int u) {
    q.push(u);
    while (!q.empty()) {
        int t = q.front(); q.pop();
        printf("visit %d\n",t);
        visited[t] = 1;
        for (auto x: v[t]) {
            //cout<<"x= "<<x<<"\n";
            if (!visited[x]) {
                q.push(x);
            }
        }
    }
}

// O(V+E): V dinh, E canh
// https://www.quora.com/Why-is-the-complexity-of-DFS-O-V+E
// neu thuc hien theo adjacent list, tai moi dinh, se travel
// den cac canh lien ke theo chieu sau theo canh gan voi dinh hien tai
// tong so canh la O(E)
// sau do visit chinh dinh lien ke
// tong so dinh la O(V) ( vi khong visit dinh da visit truoc do)
// vay tong time visit la O(E) + O(V)
void dfs(int u) {
    printf("visit %d\n",u);
    visited[u] = 1;
    for (auto x: v[u]) {
        if (!visited[x]) {
            dfs(x);
        }
    }
}


int main() {
    /*
    1-->4-->2
    -
    -->3-->5
    voi do thi tren: dinh 1 noi dinh 4, dinh 4 noi dinh 2
    dinh 1 noi dinh 3, dinh 3 noi dinh 5

    bfs: visit dinh hien tai va cac dinh lan can cua no truoc
    visit 1, cac dinh lan can cua 1 la 4,3: => visit 4,3 next
    visit tiep 2 la lan can cua 4, 5 la lan can cua 3:
    thu tu visit la: 1->4->3->2->5

    dfs: visit dinh hien tai va
    visit dinh lan can theo chieu sau den khi nao khong con dinh thi quay lai
    thu tu visit la: 1->4->2->3->5
    */
    // adjacent lists
    // moi node luu trang thai cac canh ke cua no
    // vi du node 1 ket noi 2 canh ke toi 2 dinh 2 va 3
    v[1].push_back(4);v[1].push_back(3); // v[1]={2,3}
    v[4].push_back(2); // v[2]={4}
    v[3].push_back(5); // v[3]={5}

    cout<<"travel by bfs\n";
    visited.assign(n+1,0);
    bfs(1);

    cout<<"travel by dfs\n";
    visited.assign(n+1,0);
    dfs(1);

    return 0;
}
