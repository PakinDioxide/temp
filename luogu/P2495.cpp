/*
    author  : 
    created : 24/08/2025 07:18
    task    : P2495
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 3e5+5;

int n, q, df[mxN], c[mxN], a[2*mxN], up[25][mxN], dep[mxN], it = 0;
ll wi[mxN], dp[mxN], st[mxN], id = 0;
vector <pair <int, ll>> adj[mxN];
vector <int> aux[mxN];

void dfs(int u, int p) {
    df[u] = ++it, up[0][u] = p;
    for (auto [v, w] : adj[u]) if (v != p) dep[v] = dep[u] + 1, wi[v] = min(wi[u], w), dfs(v, u);
}

bool cmp(int x, int y) {
    return df[x] < df[y];
}

int LCA(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    int k = dep[x] - dep[y];
    for (int i = 0; i < 25; i++) if (k & (1 << i)) x = up[i][x];
    if (x == y) return x;
    for (int i = 24; i >= 0; i--) if (up[i][x] != up[i][y]) x = up[i][x], y = up[i][y];
    return up[0][x];
}

void au() {
    int k; cin >> k;
    int h[k]; for (auto &e : h) cin >> e, c[e] = 1;
    id = 0;
    st[++id] = 1;
    sort(h, h+k, cmp);
    for (auto &e : h) {
        int L = LCA(e, st[id]);
        if (L != st[id]) {
            while (df[L] < df[st[id-1]]) aux[st[id-1]].emplace_back(st[id]), id--;
            if (df[L] > df[st[id-1]]) {
                aux[L].emplace_back(st[id]); st[id] = L;
            } else {
                aux[L].emplace_back(st[id]); id--;
            }
        }
        st[++id] = e;
    }
    while (id > 1) aux[st[id-1]].emplace_back((st[id])), id--;
    id = 0;
}

ll calc(int u) {
    dp[u] = 0;
    for (auto v : aux[u]) dp[u] += calc(v);
    aux[u].clear();
    if (c[u]) dp[u] = wi[u];
    else dp[u] = min(dp[u], wi[u]);
    c[u] = 0;
    return dp[u];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) { int u, v; ll w; cin >> u >> v >> w; adj[u].emplace_back(v, w); adj[v].emplace_back(u, w); }
    wi[1] = LLONG_MAX, dfs(1, 0);
    for (int c = 1; c < 25; c++) for (int i = 1; i <= n; i++) up[c][i] = up[c-1][up[c-1][i]];
    cin >> q;
    while (q--) {
        au();
        cout << calc(1) << '\n';
    }
}