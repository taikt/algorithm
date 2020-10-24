/*
Kiem tra do thi co phai la cay hop le hay khong.

An undirected graph is tree if it has following properties.
1) There is no cycle.
2) The graph is connected.
*/

#include <bits/stdc++.h>
using namespace std;
/*
// chua thong tin canh
vector<vector<int>> edge(N, vector<int>()); // hoac vector<unordered_set<int>> edge(N, unordered_set<int>())
// luu thong tin dinh da visit
vector<int> visited(N,0); // hoac unordered_set<int> visited
*/

// bfs
// sau khi visit dinh, cat tia canh lien quan, khong can dung pre de danh dau
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        queue<int> q;
        int t;
        vector<unordered_set<int>> ed(n,unordered_set<int>());
        vector<int> visited(n,0);
        for (auto x: edges) {
           ed[x[0]].insert(x[1]);
           ed[x[1]].insert(x[0]);
        }

        q.push(0);visited[0] =1;
        while (!q.empty()) {
            t = q.front(); q.pop();
            for (auto x: ed[t]) {
                if (visited[x]) return 0;
                visited[x] = 1;
                q.push(x);
                ed[x].erase(t);
            }
        }
        //for (auto x: visited) {
        //    if (!x) return 0;
        //}
        return (visited.size()==n);// kiem tra do thi co ket noi

        //return 1;
    }
};

// bfs
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        queue<int> q;
        int t;
        vector<unordered_set<int>> ed(n,unordered_set<int>());
        unordered_set<int> visited;
        for (auto x: edges) {
           ed[x[0]].insert(x[1]);
           ed[x[1]].insert(x[0]);
        }

        q.push(0);visited.insert(0);
        while (!q.empty()) {
            t = q.front(); q.pop();
            for (auto x: ed[t]) {
                if (visited.count(x)) return 0;
                visited.insert(x);
                q.push(x);
                ed[x].erase(t);
            }
        }
        return (visited.size()==n);// kiem tra do thi co ket noi
    }
};

// sau khi visit dinh, dung pre de danh dau
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

// bfs
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
    // return false neu subgraph co chu ky
    // true neu sub-graph khong co chu ky
    // sub-graph o day la la tap cac dinh connected voi dinh dang xet
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

int main() {
    //freopen("lc_261.inp","r",stdin);
    //freopen("lc_261.out","w",stdout);
    //n: so dinh
    //m: so canh
    int m,n,x,y;
    scanf("%d %d\n",&m,&n);
    vector<vector<int>> edges(n);
    FOR(i,0,m) {
        scanf("%d %d\n",&x,&y);
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    Solution anw;
    if (anw.validTree(n,edges)) cout<<"true";
    else cout<<"false";

    return 0;
}
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

