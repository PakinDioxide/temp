/*
    author  : PakinDioxide
    created : 05/04/2025 17:41
    task    : 2019_Feb_S_3
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector <pair <int, int>> adj[n+1];
    int par[n+1], vis[n+1], c[n+1];
    iota(par, par+n+1, 0);
    memset(vis, 0, sizeof(vis));
    memset(c, 0, sizeof(c));
    function <int(int)> fi = [&] (int x) {
        if (x != par[x]) return par[x] = fi(par[x]);
        return x;
    };
    for (int i = 0; i < m; i++) {
        char k;
        int u, v;
        cin >> k >> u >> v;
        if (u > v) swap(u, v);
        adj[u].emplace_back(v, (k == 'S'));
        adj[v].emplace_back(u, (k == 'S'));
        par[fi(v)] = fi(u);
    }
    function <int(int, int, int)> dfs = [&] (int u, int p, int co) {
        if (vis[u]) return (int) (c[u] == co);
        vis[u] = 1;
        c[u] = co;
        int okk = 1;
        for (auto [v, k] : adj[u]) if (v != p) okk = min(okk, dfs(v, u, k ? co : !co));
        return okk;
    };
    string ans = "1";
    for (int i = 1; i <= n; i++) {
        if (vis[fi(i)]) continue;
        if (dfs(i, i, 0)) ans += "0";
        else {cout << 0 << '\n'; return 0;}
    }
    cout << ans << '\n';
}