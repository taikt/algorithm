#include <bits/stdc++.h>
using namespace std;

int n=5;
vector<vector<int>> v(n+1, vector<int>());
vector<int> visited;
queue<int> q;

int bfs(int u) {
    q.push(u);
    while (!q.empty()) {
        int t = q.front(); q.pop();
        printf("visit %d\n",t);
        visited[t] = 1;
        for (auto x: v[t]) {
            cout<<"x= "<<x<<"\n";
            if (!visited[x]) {
                q.push(x);
            }
        }
    }
    cout<<"ok\n";
    return 0;
}

int main() {
    /*
    1-->4-->2
    -
    -->3-->5
    voi do thi tren: dinh 1 noi dinh 4, dinh 4 noi dinh 2
    dinh 1 noi dinh 3, dinh 3 noi dinh 5
    */

    v[1].push_back(4);v[1].push_back(3); // v[1]={2,3}
    v[4].push_back(2); // v[2]={4}
    v[3].push_back(5); // v[3]={5}
    visited.assign(n,0);

    bfs(1);
    cout<<"done\n";
    return 0;
}
