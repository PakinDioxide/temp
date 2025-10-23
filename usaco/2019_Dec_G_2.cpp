/*
    author  : PakinDioxide
    created : 02/08/2025 15:43
    task    : 2019_Dec_G_2
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;

int n, q, c[mxN], sz[mxN], dep[mxN], par[mxN], id[mxN], tp[mxN];
vector <multiset <pair <int, int>>> s;
vector <int> adj[mxN];

void dfs(int u, int p) {
    sz[u] = 1;
    for (auto &v : adj[u]) if (v != p) {
        dep[v] = dep[u] + 1;
        par[v] = u;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

int ct = 0;

void hld(int u, int p, int top) {
    if (u == top) s.resize(s.size()+1), id[u] = ct++;
    id[u] = id[top];
    tp[u] = top;
    s[id[u]].emplace(c[u], dep[u]);
    int idx = -1, mx = -1;
    for (auto &v : adj[u]) if (v != p && sz[v] > mx) mx = sz[v], idx = v;
    if (idx == -1) return;
    hld(idx, u, top);
    for (auto &v : adj[u]) if (v != p && v != idx) hld(v, u, v);
}

int chk(int l, int r, int idx, int c) {
    auto itl = s[idx].lower_bound(make_pair(c, l)), itr = s[idx].upper_bound(make_pair(c, r));
    return itl != itr;
}

int path(int x, int y, int c) {
    while (tp[x] != tp[y]) {
        if (dep[tp[x]] < dep[tp[y]]) swap(x, y);
        if (chk(dep[tp[x]], dep[x], id[tp[x]], c)) return 1;
        x = par[tp[x]];
    }
    if (dep[x] > dep[y]) swap(x, y);
    return chk(dep[x], dep[y], id[tp[x]], c);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i < n; i++) { int u, v; cin >> u >> v; adj[u].emplace_back(v), adj[v].emplace_back(u); }
    dfs(1, 1);
    hld(1, 1, 1);
    while (q--) {
        int x, y, c; cin >> x >> y >> c;
        cout << path(x, y, c);
    }
    cout << '\n';
}