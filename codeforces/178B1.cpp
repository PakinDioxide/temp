#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;

int n, m, k;
vector <int> adj[mxN];

int it = 0, id[mxN], lo[mxN], onst[mxN];
stack <int> st;

void dfs(int u, int p) {
    id[u] = lo[u] = ++it;
    onst[u] = 1;
    st.emplace(u);
    for (auto v : adj[u]) if (v != p) {
        if (!id[v]) dfs(v, u);
        if (onst[v]) lo[u] = min(lo[u], lo[v]);
    }
    if (lo[u] == id[u]) {
        while (1) {
            int x = st.top();
            st.pop();
            lo[x] = lo[u];
            onst[x] = 0;
            if (x == u) break;
        }
    }
}

set <int> adt[mxN];

int dep[mxN], up[25][mxN];

void dd(int u, int p) {
    dep[u] = dep[p]+1;
    up[0][u] = p;
    for (auto v : adt[u]) if (v != p) {
        dd(v, u);
    }
}

int LCA(int u, int v) {
    if (dep[v] > dep[u]) swap(u, v);
    int k = dep[u] - dep[v];
    for (int i = 0; i < 25; i++) if (k & (1 << i)) u = up[i][u];
    if (u == v) return u;
    for (int i = 24; i >= 0; i--) if (up[i][u] != up[i][v]) u = up[i][u], v = up[i][v];
    return up[0][u];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    vector <pair <int, int>> E(m);
    for (auto &[u, v] : E) cin >> u >> v, adj[u].emplace_back(v), adj[v].emplace_back(u);
    dfs(1, 1);
    for (int i = 1; i <= n; i++) for (auto &v : adj[i]) if (lo[i] != lo[v]) adt[lo[i]].emplace(lo[v]);
    dd(lo[1], 0);
    for (int c = 1; c < 25; c++) for (int i = 1; i <= n; i++) up[c][i] = up[c-1][up[c-1][i]];
    int q; cin >> q;
    while (q--) {
        int u, v; cin >> u >> v;
        u = lo[u], v = lo[v];
        int L = LCA(u, v);
        cout << dep[u] - dep[L] + dep[v] - dep[L] << '\n';
    }
}

