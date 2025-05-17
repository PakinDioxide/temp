/*
    author  : PakinDioxide
    created : 11/05/2025 15:49
    task    : 1138_2
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;

int n, q, st[mxN], en[mxN], it = 0;
ll fen[mxN], a[mxN];
vector <int> adj[mxN];

void upd(int idx, ll x) { for (int i = idx; i <= n; i += i & -i) fen[i] += x; }
ll qr(int idx) { ll x = 0; for (int i = idx; i > 0; i -= i & -i) x += fen[i]; return x; }

void dfs(int u, int p) {
    st[u] = ++it;
    for (auto v : adj[u]) if (v != p) dfs(v, u);
    en[u] = it+1;
    upd(st[u], a[u]);
    upd(en[u], -a[u]);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1, u, v; i < n; i++) cin >> u >> v, adj[u].emplace_back(v), adj[v].emplace_back(u);
    dfs(1, 1);
    while (q--) {
        int t; cin >> t;
        if (t == 1) { int u; ll x; cin >> u >> x; upd(st[u], x-a[u]); upd(en[u], a[u]-x); a[u] = x; }
        else { int u; cin >> u; cout << qr(st[u]) << '\n'; }
    }
}