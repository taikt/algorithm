#include <bits/stdc++.h>
using namespace std;

#define N=5
vector<vector<int>> v(N, vector<int>());

int main() {
    v[1].push_back(2);v[1].push_back(3);
    v[2].push_back(1); v[2].push_back(3);
    v[3].push_back(1); v[3].push_back(2); v[3].push_back(4);
    v[4].push_back(3);

    if (bfs(1)) cout<<"unvalid tree\n";
    else cout<<"valid tree\n";

    return 0;
}
