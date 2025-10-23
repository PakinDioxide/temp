/*
    author  : PakinDioxide
    created : 09/04/2025 15:16
    task    : 1139
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    ll c[n], ans[n];
    set <ll> s[n];
    for (auto &e : c) cin >> e;
    vector <int> adj[n];
    for (int i = 1; i < n; i++) { int u, v; cin >> u >> v; u--, v--; adj[u].emplace_back(v), adj[v].emplace_back(u); }
    auto m = [&] (int x, int y) {
        if (s[x].size() < s[y].size()) swap(s[x], s[y]);
        for (auto &e : s[y]) s[x].emplace(e);
    };
    function <void(int, int)> dfs = [&] (int u, int p) {
        s[u].emplace(c[u]);
        for (auto v : adj[u]) {
            if (v == p) continue;
            dfs(v, u);
            m(u, v);
        }
        ans[u] = s[u].size();
    };
    dfs(0, 0);
    for (auto &e : ans) cout << e << ' ';
    cout << '\n';
}