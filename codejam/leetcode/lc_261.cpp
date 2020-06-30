#include <bits/stdc++.h>
using namespace std;

#define N 5
vector<vector<int>> v(N, vector<int>());
queue<int> q;
vector<int> visited(N,0);
vector<int> pre(N,0);

bool bfs(int u) {
    q.push(u);visited[u]=1;
    int t=0;
    while (!q.empty()) {
        t=q.front(); q.pop();
        //visited[t] = 1;
        for (auto x: v[t]) {
            if (x != pre[t] && visited[x]) {
                return false;
            }
            else if (!visited[x]){
                pre[x] = t;
                q.push(x); visited[x] = 1;
            }
        }
    }
    return true;

}

int main() {
    v[1].push_back(2);v[1].push_back(3);
    v[2].push_back(1); v[2].push_back(3);
    v[3].push_back(1); v[3].push_back(2); v[3].push_back(4);
    v[4].push_back(3);

    if (bfs(1)) cout<<"valid tree\n";
    else cout<<"unvalid tree\n";

    return 0;
}
