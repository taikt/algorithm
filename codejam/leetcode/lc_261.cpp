/*
Kiem tra do thi co phai la cay hop le hay khong.

An undirected graph is tree if it has following properties.
1) There is no cycle.
2) The graph is connected.
*/

#include <bits/stdc++.h>
using namespace std;

#define N 5
vector<vector<int>> v(N, vector<int>());
queue<int> q;
vector<int> visited(N,0);
vector<int> pre(N,0);

// bfs
bool bfs(int u) {
    // kiem tra do thi khong chu ki
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
    // kiem tra do thi ket noi
    for (auto x: visited)
        if (!x) return false;

    return true;

}

// return false neu subgraph co chu ky
// true neu sub-graph khong co chu ky
// sub-graph o day la la tap cac dinh connected voi dinh dang xet
bool dfs(int u) {
    visited[u] = 1;
    for (auto x: v[u]) {
        if (visited[x] && (pre[u] != x)) // unvalid tree
        {
            return false;
        } else if (!visited[x]) { // dfs dinh next
            pre[x] = u;
            if (!dfs(x)) return false;
            //if (dfs(x,v,visited,pre)) return true; // wrong if use like this
        }
    }
    return true;
}

int main() {
    v[1].push_back(2);v[1].push_back(3);
    v[2].push_back(1); v[2].push_back(3);
    v[3].push_back(1); v[3].push_back(2); v[3].push_back(4);
    v[4].push_back(3);

// bfs method
#if 0
    if (bfs(1)) cout<<"valid tree\n";
    else cout<<"unvalid tree\n";
#endif // 0

// dfs method
#if 1
    // kiem tra do thi ket noi
    bool valid = dfs(1);
    for (auto x: visited)
    if (!x) {
        valid = false; break;
    };
    if (valid) cout<<"valid tree\n";
    else cout<<"unvalid tree\n";
#endif // 1

// TODO: union-find method
    return 0;
}

// leetcode submit: pass
#if 1
//bfs
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> v(n,vector<int>());
        for (auto ed: edges) {
            v[ed[0]].push_back(ed[1]);
            v[ed[1]].push_back(ed[0]);
        }
        if (bfs(0,n,v)) return 1;
        else return 0;
    }

    bool bfs(int u,int N, vector<vector<int>>& v) {
        // kiem tra do thi khong chu ki
        queue<int> q;
        vector<int> visited(N,0);
        vector<int> pre(N,0);
        q.push(u);visited[u]=1;

        //for (auto x: visited)
          //  cout<<"init:"<<x<<"\n";

        int t=0;
        while (!q.empty()) {
            t=q.front(); q.pop();
            //visited[t] = 1;
            for (auto x: v[t]) {
                //cout<<"chech x: "<<x<<"\n";
                if (x != pre[t] && visited[x]) {
                    return false;
                }
                else if (!visited[x]){
                    pre[x] = t;
                    q.push(x); visited[x] = 1;
                    //cout<<"add: "<<visited[x]<<"\n";
                }
            }
        }

        // for (auto x: visited)
         //   cout<<"out:"<<x<<"\n";

        // kiem tra do thi ket noi
        for (auto x: visited)
            if (!x) return false;

        return true;
    }

};

// bfs 2
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        queue<int> q;
        q.push(0);
        vector<bool> visited(n,false);
        vector<int> pre(n,-1);
        int t=-1;
        while (!q.empty()) {
            t = q.front(); q.pop();
            visited[t]=true;
            for(auto v:edges[t]) {
                if (!visited[v]) {
                    q.push(v);
                    pre[v]=t;
                } else if (v!=pre[t]) // neu dinh v da duoc tham ma khong phai la parent cua t thi do thi co chu trinh
                return false;
            }
        }
        return true;
    }
};

int main() {
    freopen("lc_261.inp","r",stdin);
    freopen("lc_261.out","w",stdout);
    //m: so dinh
    //n: so canh
    int m,n,x,y;
    scanf("%d %d\n",&m,&n);
    vector<vector<int>> edges(m);
    FOR(i,0,n) {
        scanf("%d %d\n",&x,&y);
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    Solution anw;
    if (anw.validTree(m,edges)) cout<<"true";
    else cout<<"false";

    return 0;
}


//dfs 1
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> v(n,vector<int>());
        vector<int> visited(n,0);
        vector<int> pre(n,0);
        for (auto ed: edges) {
            v[ed[0]].push_back(ed[1]);
            v[ed[1]].push_back(ed[0]);
        }
        bool valid = dfs(0,v,visited,pre);
        for (auto x: visited)
        if (!x) {
            return false;
        };
        return valid;
    }

    bool dfs(int u,vector<vector<int>>&v,vector<int>& visited, vector<int>& pre) {
        visited[u] = 1;
        for (auto x: v[u]) {
            if (visited[x] && (pre[u] != x)) // unvalid tree
            {
                return false;
            } else if (!visited[x]) { // dfs dinh next
                pre[x] = u;
                if (!dfs(x,v,visited,pre)) return false;
            }
        }
        return true;
    }
};

//dfs 2: improve dfs1
// su du bien pre kieu int, khong can vector
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> v(n,vector<int>());
        vector<int> visited(n,0);
        //vector<int> pre(n,0);
        for (auto ed: edges) {
            v[ed[0]].push_back(ed[1]);
            v[ed[1]].push_back(ed[0]);
        }
        bool valid = dfs(0,v,visited,-1);
        for (auto x: visited)
        if (!x) {
            return false;
        };
        return valid;
    }

    bool dfs(int u,vector<vector<int>>&v,vector<int>& visited, int pre) {
        visited[u] = 1;
        for (auto x: v[u]) {
            if (visited[x] && (pre != x)) // unvalid tree
            {
                return false;
            } else if (!visited[x]) { // dfs dinh next

                if (!dfs(x,v,visited,u)) return false;
            }
        }
        return true;
    }

};

// dfs 3: improve dfs 2
// simpler code
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> v(n,vector<int>());
        vector<int> visited(n,0);
        //vector<int> pre(n,0);
        for (auto ed: edges) {
            v[ed[0]].push_back(ed[1]);
            v[ed[1]].push_back(ed[0]);
        }
        bool valid = dfs(0,v,visited,-1);
        for (auto x: visited)
        if (!x) {
            return false;
        };
        return valid;
    }

    bool dfs(int u,vector<vector<int>>&v,vector<int>& visited, int pre) {
        if (visited[u]) return false;
        visited[u] = 1;
        for (auto x: v[u]) {
            if (pre != x)
            {
                if (!dfs(x,v,visited,u)) return false;
            }
        }
        return true;
    }
};
//note
/*
neu dau vao la vector canh mot chieu (su dung pair), convert ra vector 2 chieu nhu sau
 input: vector<pair<int,int>>& edges)
 vector<vector<int>> g(n,vector<int>());
        for (auto a:edges) {
            g[a.first].push_back(a.second);
            g[a.second].push_back(a.first);
        }
*/
#endif // 0
