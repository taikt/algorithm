#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000 + 10;
const int MAXM = 100000 + 10;
const int MAXK = 10 + 10;
const int MAXT = 5;
const long long INF = (long long)(1e15);

struct Edge {
    int u, v, c;

    Edge() {}
    Edge(int _u, int _v, int _c) {
        u = _u; v = _v; c = _c;
    }

    int next(int x) {
        return ((x == u) ? v : u);
    }
};

int n, m, K, n_easy;
vector<int> adj[MAXN];
Edge edges[MAXM];
int a[MAXK], b[MAXK], easy[MAXK];
vector<int> ls_easy;

long long sp[MAXK][2][MAXN];
long long f[MAXN][(1 << MAXT)][MAXT + 1];
int topo[MAXN];
bool sure[MAXM][2];

void dijkstra(int from, int to, long long *D) {
    for(int i = 1; i <= n; ++i) D[i] = INF;
    D[from] = 0;
    priority_queue< pair<long long, int>, vector< pair<long long, int> >, greater< pair<long long, int> > > q;
    q.push(make_pair(D[from], from));
    while (!q.empty()) {
        pair<long long, int> t = q.top();
        q.pop();

        int u = t.second;
        if (u == to) break;
        if (D[u] != t.first) continue;

        for(int &eid : adj[u]) {
            int v = edges[eid].next(u);
            if (D[v] > D[u] + edges[eid].c) {
                D[v] = D[u] + edges[eid].c;
                q.push(make_pair(D[v], v));
            }
        }
    }
}

// check if edge (u, v, c) lies on the shortest path from a[i] to b[i]
bool on_shortest(int i, int u, int v, int c) {
    return (sp[i][0][u] + c + sp[i][1][v] == sp[i][0][ b[i] ]);
}

void init() {
    scanf("%d %d %d\n", &n, &m, &K); //cin >> n >> m >> K;
    for(int i = 1; i <= m; ++i) {
        scanf("%d %d %d\n", &edges[i].u, &edges[i].v, &edges[i].c); //cin >> edges[i].u >> edges[i].v >> edges[i].c;
        adj[ edges[i].u ].push_back(i);
        adj[ edges[i].v ].push_back(i);
    }
    scanf("%d %d\n", &a[1], &b[1]); //cin >> a[1] >> b[1];
    ls_easy.clear(); n_easy = 0;
    for(int i = 2; i <= K; ++i) {
        scanf("%d %d %d\n", &easy[i], &a[i], &b[i]); //cin >> easy[i] >> a[i] >> b[i];
        if (easy[i] == 1) {
            n_easy++;
            ls_easy.push_back(i);
        }
    }
    assert(n_easy <= MAXT);

    //cout << "read done\n";

    for(int i = 1; i <= K; ++i) {
        dijkstra(a[i], b[i], sp[i][0]);
        dijkstra(b[i], a[i], sp[i][1]);
        if ((i >= 2) && (easy[i] == 0)) {
            //if can not change start time of person i
            for(int eid = 1; eid <= m; ++eid) {
                if (on_shortest(i, edges[eid].u, edges[eid].v, edges[eid].c) && (sp[1][0][edges[eid].u] == sp[i][0][edges[eid].u]))
                    sure[eid][0] = true;
                if (on_shortest(i, edges[eid].v, edges[eid].u, edges[eid].c) && (sp[1][0][edges[eid].v] == sp[i][0][edges[eid].v]))
                    sure[eid][1] = true;
            }
        }
    }
}

bool cmp(int u, int v) {
    return (sp[1][0][u] < sp[1][0][v]);
}

int get_bit(int x, int n) {
    return ((x >> n) & 1);
}

void maximize(long long &a, long long b) {
    if (b > a) a = b;
}

void update(int eid, int u, int v, int c) {
    int rev = (u == edges[eid].v);
    int len_sure = (sure[eid][rev] == true) ? c : 0;

    for(int mask = 0; mask < (1 << n_easy); ++ mask) {
        long long x = f[u][mask][0];
        for(int i = 0; i < n_easy; ++i)
            if (get_bit(mask, i) == 1)
                maximize(x, f[u][mask][i + 1]);

        for(int i = 0; i < n_easy; ++i) {

            if (on_shortest(ls_easy[i], u, v, c)) {
                if (get_bit(mask, i) == 1) {
                    // case: continue
                    maximize(f[v][mask][i + 1], f[u][mask][i + 1] + c);
                }
                else {
                    // case: end current, extend
                    maximize(f[v][mask + (1 << i)][i + 1], x + c);
                }
            }
        }

        // case: end current, no extend
        maximize(f[v][mask][0], x + len_sure);
    }
}

void solve() {
    for(int i = 1; i <= n; ++i) topo[i] = i;
    sort(topo + 1, topo + n + 1, cmp);
    assert(topo[1] == a[1]);

    f[ a[1] ][0][0] = 0;
    for(int i = 1; i <= n; ++i) {
        int u = topo[i];
        for(int &eid : adj[u]) {
            int v = edges[eid].next(u), c = edges[eid].c;
            if (on_shortest(1, u, v, c)) {
                update(eid, u, v, c);
            }
        }
    }

    long long res = 0;
    for(int mask = 0; mask < (1 << n_easy); ++mask) {
        maximize(res, f[ b[1] ][mask][0]);
        for(int i = 0; i < n_easy; ++i)
            if (get_bit(mask, i) == 1)
                maximize(res, f[ b[1] ][mask][i + 1]);
    }

    cout << res << "\n";
}

void run() {
    init();
    solve();
}

int main() {
    freopen("workout.inp","r",stdin);
    freopen("workout.out","w",stdout);
    //freopen("workout.inp", "r", stdin);
    //freopen("workout.out", "w", stdout);

    int ntests = 1;
    for(int tc = 1; tc <= ntests; ++tc) {
        run();
    }
}
