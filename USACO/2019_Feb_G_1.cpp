/*
    author  : PakinDioxide
    created : 11/05/2025 15:35
    task    : 2019_Feb_G_1
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;

int n, q, st[mxN], en[mxN], it = 0, up[25][mxN], dep[mxN];
ll a[mxN], fen[mxN];
vector <int> adj[mxN];

void upd(int idx, ll x) { for (int i = idx; i <= n; i += i & -i) fen[i] ^= x; }
ll qr(int idx) { ll x = 0; for (int i = idx; i > 0; i -= i & -i) x ^= fen[i]; return x; }

void dfs(int u, int p) {
    st[u] = ++it;
    up[0][u] = p;
    for (auto v : adj[u]) if (v != p) dep[v] = dep[u]+1, dfs(v, u);
    en[u] = it+1;
    upd(st[u], a[u]);
    upd(en[u], a[u]);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("cowland.in", "r", stdin);
    freopen("cowland.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1, u, v; i < n; i++) cin >> u >> v, adj[u].emplace_back(v), adj[v].emplace_back(u);
    dfs(1, 1);
    for (int i = 1; i < 25; i++) for (int j = 1; j <= n; j++) up[i][j] = up[i-1][up[i-1][j]];
    while (q--) {
        int t; cin >> t;
        if (t == 1) { int u; ll x; cin >> u >> x; upd(st[u], a[u] ^ x); upd(en[u], a[u] ^ x); a[u] = x; }
        else {
            int u, v; cin >> u >> v;
            ll val = qr(st[u]) ^ qr(st[v]);
            if (dep[u] < dep[v]) swap(u, v);
            int d = dep[u] - dep[v];
            for (int i = 0; i < 25; i++) if (d & (1 << i)) u = up[i][u];
            if (u == v) { cout << (val ^ a[u]) << '\n'; continue; }
            for (int i = 24; i >= 0; i--) if (up[i][u] != up[i][v]) u = up[i][u], v = up[i][v];
            cout << (val ^ a[up[0][u]]) << '\n';
        }
    }
}