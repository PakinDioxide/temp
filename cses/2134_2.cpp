/*
    author  : 
    created : 02/08/2025 15:01
    task    : 2134_2
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;

int n, q, par[mxN], dep[mxN], sz[mxN], tp[mxN], id[mxN];
vector <int> adj[mxN];
int seg[2*mxN], a[mxN];

void upd(int idx, ll x) {
    idx += n; seg[idx] = x; idx /= 2;
    while (idx) seg[idx] = max(seg[idx<<1], seg[idx<<1|1]), idx /= 2;
}

int qr(int l, int r) {
    l += n, r += n+1; int k = 0;
    while (l < r) {
        if (l & 1) k = max(k, seg[l++]);
        if (r & 1) k = max(k, seg[--r]);
        l /= 2, r /= 2;
    }
    return k;
}

void dfs(int u, int p) {
    sz[u] = 1;
    for (auto &v : adj[u]) if (v != p) {
        par[v] = u;
        dep[v] = dep[u] + 1;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

int ct = 0;

void hld(int u, int p, int top) {
    id[u] = ++ct;
    tp[u] = top;
    int mx = -1, idx = -1;
    for (auto &v : adj[u]) if (v != p) {
        if (mx < sz[v]) {
            mx = sz[v];
            idx = v;
        }
    }
    if (idx == -1) return;
    hld(idx, u, top);
    for (auto &v : adj[u]) if (v != p && v != idx) hld(v, u, v);
}

int path(int x, int y) {
    int k = 0;
    while (tp[x] != tp[y]) {
        if (dep[tp[x]] < dep[tp[y]]) swap(x, y);
        k = max(k, qr(id[tp[x]], id[x]));
        x = par[tp[x]];
    }
    if (dep[x] > dep[y]) swap(x, y);
    k = max(k, qr(id[x], id[y]));
    return k;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) { int u, v; cin >> u >> v; adj[u].emplace_back(v), adj[v].emplace_back(u); }
    dfs(1, 1);
    hld(1, 1, 1);
    for (int i = 1; i <= n; i++) upd(id[i], a[i]);
    while (q--) {
        int t; cin >> t;
        if (t == 1) { int u; int x; cin >> u >> x; upd(id[u], x); }
        else { int x, y; cin >> x >> y; cout << path(x, y) << ' '; }
    }
    cout << '\n';
}