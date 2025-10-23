/*
    author  : 
    created : 26/08/2025 21:59
    task    : 2134D
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;

int n, sz[mxN], nx[mxN], par[mxN], dis;
vector <int> adj[mxN];

pair <int, int> dfs(int u, int p) {
    int idx = u, d = 0; nx[u] = u;
    for (auto v : adj[u]) if (v != p) {
        pair <int, int> k = dfs(v, u);
        if (k.second+1 > d) idx = k.first, d = k.second+1, nx[u] = v;
    }
    return {idx, d};
}

void fsz(int u, int p) {
    sz[u] = INT_MAX;
    par[u] = p;
    for (auto v : adj[u]) if (v != p) fsz(v, u), sz[u] = min(sz[u], sz[v]);
    if (sz[u] == INT_MAX) sz[u] = 0;
    sz[u]++;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) adj[i].clear(), sz[i] = 0;
    for (int i = 1, u, v; i < n; i++) cin >> u >> v, adj[u].emplace_back(v), adj[v].emplace_back(u);
    int L = dfs(1, 1).first;
    for (int i = 1; i <= n; i++) nx[i] = i;
    dis = dfs(L, L).second;
    if (dis == n-1) { cout << -1 << '\n'; return; }
    vector <int> a;
    while (a.empty() || a.back() != L) {
        a.emplace_back(L);
        L = nx[L];
    }
    int C = a[ceil((int) a.size() / 2.0)];
    fsz(C, C);
    int x = -1;
    for (int i = 1; i <= n; i++) if (adj[i].size() >= 3) { x = i; break; }
    // cout << "C : " << C << '\n';
    if (x != C) {
        int p = par[x];
        auto cmp = [&] (int X, int Y) {
            return (X == p ? 0 : sz[X] < sz[Y]);
        };
        cout << p << ' ' << x << ' ' << adj[x][0] << '\n';
        return;
    } else {
        auto cmp = [&] (int x, int y) {
            return sz[x] < sz[y];
        };
        sort(adj[C].begin(), adj[C].end(), cmp);
        cout << adj[C][0] << ' ' << C << ' ' << adj[C][1] << '\n';
        return;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}