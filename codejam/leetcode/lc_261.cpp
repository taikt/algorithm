#include <bits/stdc++.h>
using namespace std;

#define N=5
vector<vector<int>> v(N, vector<int>());
queue<int> q;
vector<int> visited;

bool bfs(int u) {
    q.push(u);
    while (!.q.empty()) {
        t=q.front(); q.pop();
        visited[t] = 1;
        for (auto x: v[t]) {
            pre[x] = t;
            q.push(x);
        }
    }

}

int main() {
    v[1].push_back(2);v[1].push_back(3);
    v[2].push_back(1); v[2].push_back(3);
    v[3].push_back(1); v[3].push_back(2); v[3].push_back(4);
    v[4].push_back(3);

    if (bfs(1)) cout<<"unvalid tree\n";
    else cout<<"valid tree\n";

    return 0;
}
