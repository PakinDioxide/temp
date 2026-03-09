#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;

int a[mxN];
vector <int> adj[mxN];

struct Node {
    int val, l, r;
};

int seg[mxN], it = 0;
Node pool[mxN<<5];

int nw(int x) {
    pool[++it] = {x, 0, 0};
    return it;
}

int nw(int L, int R) {
    pool[++it] = {pool[L].val+pool[R].val, L, R};
    return it;
}

int build(int l, int r) {
    if (l == r) return nw(0);
    else {
        int m = l + (r-l)/2;
        return nw(build(l, m), build(m+1, r));
    }
}

int upd(int l, int r, int x, int k, int u) {
    if (l == r) return nw(pool[u].val + k);
    else {
        int m = l + (r-l)/2;
        if (m >= x) return nw(upd(l, m, x, k, pool[u].l), pool[u].r);
        else return nw(pool[u].l, upd(m+1, r, x, k, pool[u].r));
    }
}

int qr(int l, int r, int u, int v, int lca, int lcau, int x) {
    if (l == r) return pool[u].val + pool[v].val - pool[lca].val - pool[lcau].val;
    else {
        int m = l + (r-l)/2;
        if (m >= x) return qr(l, m, pool[u].l, pool[v].l, pool[lca].l, pool[lcau].l, x);
        else return qr(m+1, r, pool[u].r, pool[v].r, pool[lca].r, pool[lcau].r, x);
    }
}

int up[30][mxN], dep[mxN], n;

void dfs(int u, int p) {
    up[0][u] = p;
    seg[u] = upd(1, n, a[u], 1, seg[p]);
    dep[u] = dep[p]+1;
    for (auto v : adj[u]) if (v != p) dfs(v, u);
}

int LCA(int u, int v) {
    if (dep[v] > dep[u]) swap(u, v);
    int k = dep[u] - dep[v];
    for (int i = 0; i < 30; i++) if (k & (1 << i)) u = up[i][u];
    if (u == v) return u;
    for (int i = 29; i >= 0; i--) if (up[i][u] != up[i][v]) u = up[i][u], v = up[i][v];
    return up[0][u];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    while (cin >> n) {
        it = 0;
        for (int i = 1; i <= n; i++) adj[i].clear(), seg[i] = 0, dep[i] = 0;
        int q; cin >> q;
        vector <int> cc;
        for (int i = 1; i <= n; i++) cin >> a[i], cc.emplace_back(a[i]);
        sort(cc.begin(), cc.end());
        for (int i = 1; i <= n; i++) a[i] = upper_bound(cc.begin(), cc.end(), a[i]) - cc.begin();
        for (int i = 1, u, v; i < n; i++) cin >> u >> v, adj[u].emplace_back(v), adj[v].emplace_back(u);
        seg[0] = build(1, n);
        dfs(1, 0);
        for (int c = 1; c < 30; c++) for (int i = 1; i <= n; i++) up[c][i] = up[c-1][up[c-1][i]];
        while (q--) {
            int u, v, x; cin >> u >> v >> x;
            int xx = upper_bound(cc.begin(), cc.end(), x) - cc.begin();
            if (xx == 0 || cc[xx-1] != x) { cout << "NotFind\n"; continue; }
            int t = LCA(u, v);
            if (qr(1, n, seg[u], seg[v], seg[t], seg[up[0][t]], xx)) cout << "Find\n";
            else cout << "NotFind\n";
        }
        cout << '\n';
    }
}