/*
    author  : 
    created : 03/08/2025 18:07
    task    : 2011_Dec_G_3
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;

int n, q, sz[mxN], dep[mxN], par[mxN], seg[4*mxN], tp[mxN], id[mxN], lz[4*mxN];
vector <int> adj[mxN];

void push(int u, int ls, int rs) {
    seg[u<<1] += ls*lz[u], seg[u<<1|1] += rs*lz[u];
    lz[u<<1] += lz[u], lz[u<<1|1] += lz[u];
    lz[u] = 0;
}

void upd(int l, int r, int x, int y, int u) {
    int mid = l + (r-l)/2;
    if (x <= l && r <= y) seg[u] += (r-l+1), lz[u]++;
    else {
        push(u, mid-l+1, r-mid);
        if (mid >= x) upd(l, mid, x, y, u<<1);
        if (mid+1 <= y) upd(mid+1, r, x, y, u<<1|1);
        seg[u] = seg[u<<1] + seg[u<<1|1];
    }
}

int qr(int l, int r, int x, int y, int u) {
    if (x <= l && r <= y) return seg[u];
    else {
        int mid = l + (r-l)/2, k = 0;
        push(u, mid-l+1, r-mid);
        if (mid >= x) k += qr(l, mid, x, y, u<<1);
        if (mid+1 <= y) k += qr(mid+1, r, x, y, u<<1|1);
        return k;
    }
}

void dfs(int u, int p) {
    sz[u] = 1;
    for (auto &v : adj[u]) if (v != p) {
        dep[v] = dep[u] +  1;
        par[v] = u;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

int ct = 0;

void hld(int u, int p, int top) {
    tp[u] = top;
    id[u] = ++ct;
    int mx = -1, idx = -1;
    for (auto &v : adj[u]) if (v != p && mx < sz[v]) mx = sz[v], idx = v;
    if (idx == -1) return;
    hld(idx, u, top);
    for (auto &v : adj[u]) if (v != p && v != idx) hld(v, u, v);
}

void updp(int x, int y) {
    while (tp[x] != tp[y]) {
        if (dep[tp[x]] < dep[tp[y]]) swap(x, y);
        upd(1, n, id[tp[x]], id[x], 1);
        x = par[tp[x]];
    }
    if (x == y) return;
    if (dep[x] > dep[y]) swap(x, y);
    upd(1, n, id[x]+1, id[y], 1);
}

int qry(int x, int y) {
    int k = 0;
    while (tp[x] != tp[y]) {
        if (dep[tp[x]] < dep[tp[y]]) swap(x, y);
        k += qr(1, n, id[tp[x]], id[x], 1);
        x = par[tp[x]];
    }
    if (x == y) return k;
    if (dep[x] > dep[y]) swap(x, y);
    k += qr(1, n, id[x]+1, id[y], 1);
    return k;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i < n; i++) { int u, v; cin >> u >> v; adj[u].emplace_back(v); adj[v].emplace_back(u); }
    dfs(1, 1);
    hld(1, 1, 1);
    while (q--) {
        char t; cin >> t;
        if (t == 'P') { int x, y; cin >> x >> y; updp(x, y); }
        else { int x, y; cin >> x >> y; cout << qry(x, y) << '\n'; }
    }
}