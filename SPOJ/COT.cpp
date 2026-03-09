#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;

int n, q, a[mxN];

struct Node {
    int val, l, r;
};

int seg[mxN], it = 0, up[mxN][25], dep[mxN];
vector <int> adj[mxN];
Node pool[mxN<<5];

int nw(int x) {
    pool[++it] = {x, 0, 0};
    return it;
}

int nw2(int L, int R) {
    pool[++it] = {pool[L].val + pool[R].val, L, R};
    return it;
}

int build(int l, int r) {
    if (l == r) return nw(0);
    else {
        int m = l + (r-l)/2;
        return nw2(build(l, m), build(m+1, r));
    }
}

int upd(int l, int r, int x, int k, int u) {
    if (l == r) return nw(pool[u].val + k);
    else {
        int m = l + (r-l)/2;
        if (m >= x) return nw2(upd(l, m, x, k, pool[u].l), pool[u].r);
        else return nw2(pool[u].l, upd(m+1, r, x, k, pool[u].r));
    }
}

void dfs(int u, int p) {
    dep[u] = dep[p]+1;
    up[u][0] = p;
    seg[u] = seg[p];
    seg[u] = upd(1, n, a[u], 1, seg[u]);
    for (auto v : adj[u]) if (v != p) dfs(v, u);
}

int lca(int u, int v) {
    if (dep[v] > dep[u]) swap(u, v);
    int k = dep[u] - dep[v];
    for (int i = 0; i < 25; i++) if (k & (1 << i)) u = up[u][i];
    if (u == v) return u;
    for (int i = 24; i >= 0; i--) if (up[u][i] != up[v][i]) u = up[u][i], v = up[v][i];
    return up[u][0];
}

int qr(int l, int r, int L, int R, int LCA, int LCAU, int k) {
    if (l == r) return l;
    else {
        int m = l + (r-l)/2;
        int c = pool[pool[L].l].val + pool[pool[R].l].val - pool[pool[LCA].l].val - pool[pool[LCAU].l].val;
        if (c >= k) return qr(l, m, pool[L].l, pool[R].l, pool[LCA].l, pool[LCAU].l, k);
        else return qr(m+1, r, pool[L].r, pool[R].r, pool[LCA].r, pool[LCAU].r, k-c);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    vector <int> cc;
    for (int i = 1; i <= n; i++) cin >> a[i], cc.emplace_back(a[i]);
    sort(cc.begin(), cc.end());
    for (int i = 1; i <= n; i++) a[i] = upper_bound(cc.begin(), cc.end(), a[i]) - cc.begin();
    for (int i = 0, u, v; i < n-1; i++) cin >> u >> v, adj[u].emplace_back(v), adj[v].emplace_back(u);
    seg[0] = build(1, n);
    dfs(1, 0);
    for (int c = 1; c < 25; c++) for (int i = 1; i <= n; i++) up[i][c] = up[up[i][c-1]][c-1];
    while (q--) {
        int u, v, k; cin >> u >> v >> k;
        cout << cc[qr(1, n, seg[u], seg[v], seg[lca(u, v)], seg[up[lca(u, v)][0]], k) - 1] << '\n';
    }
}