#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;
const ll mod = 1e9+7;

int n, m, id[mxN], lo[mxN], it = 0, onst[mxN], dep[mxN], up[30][mxN], cc[mxN], cnt[mxN];
vector <int> adj[mxN];
unordered_set <int> adt[mxN];
vector <pair <int, int>> E;
stack <int> st;

void dfs(int u, int p) {
    id[u] = lo[u] = ++it, onst[u] = 1;
    st.emplace(u);
    for (auto v : adj[u]) if (v != p) {
        if (!id[v]) dfs(v, u);
        if (onst[v]) lo[u] = min(lo[u], lo[v]);
    }
    if (id[u] == lo[u]) {
        while (1) {
            int x = st.top(); st.pop();
            lo[x] = lo[u];
            onst[x] = 0;
            if (x == u) break;
        }
    }
}

void dfs2(int u, int p) {
    up[0][u] = p, cnt[u] += (cc[u] > 1);
    dep[u] = dep[p] + 1;
    for (auto v : adt[u]) if (v != p) cnt[v] += cnt[u], dfs2(v, u);
}

int LCA(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    int k = dep[u] - dep[v];
    for (int i = 0; i < 30; i++) if (k & (1 << i)) u = up[i][u];
    if (u == v) return u;
    for (int i = 29; i >= 0; i--) if (up[i][u] != up[i][v]) u = up[i][u], v = up[i][v];
    return up[0][u];
}

ll poww(ll x, ll y) {
    if (y == 0) return 1;
    ll k = poww(x, y/2);
    k *= k, k %= mod;
    if (y % 2 == 1) k *= x, k %= mod;
    return k;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    E.resize(m);
    for (auto &[u, v] : E) cin >> u >> v, adj[u].emplace_back(v), adj[v].emplace_back(u);
    dfs(1, 0);
    for (auto &[u, v] : E) if (lo[u] != lo[v]) adt[lo[u]].emplace(lo[v]), adt[lo[v]].emplace(lo[u]);
    for (int i = 1; i <= n; i++) cc[lo[i]]++;
    dfs2(lo[1], 0);
    for (int c = 1; c < 30; c++) for (int i = 1; i <= n; i++) up[c][i] = up[c-1][up[c-1][i]];
    int q; cin >> q;
    while (q--) {
        int u, v; cin >> u >> v; u = lo[u], v = lo[v];
        int lca = LCA(u, v);
        cout << poww(2, cnt[u] + cnt[v] - cnt[lca] - cnt[up[0][lca]]) << '\n';
    }
}

