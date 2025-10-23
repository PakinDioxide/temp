/*
    author  : 
    created : 23/06/2025 21:59
    task    : 2112D
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    vector <int> adj[n+1];
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].emplace_back(v), adj[v].emplace_back(u);
    }
    int p = -1, q = -1, x = -1;
    for (int i = 1; i <= n; i++) if (adj[i].size() == 2) x = i, p = adj[i][0], q = adj[i][1];
    if (p == -1) { cout << "NO\n"; return; }
    vector <pair <int, int>> edg;
    function <void(int, int, int, int)> dfs = [&] (int u, int p, int lv, int k) {
        for (auto v : adj[u]) if (v != p) {
            if (lv % 2 == k) edg.emplace_back(u, v);
            else edg.emplace_back(v, u);
            dfs(v, u, lv+1, k);
        }
    };
    dfs(p, x, 0, 0);
    dfs(q, x, 0, 1);
    cout << "YES\n";
    edg.emplace_back(p, x), edg.emplace_back(x, q);
    for (auto &[x, y] : edg) cout << x << ' ' << y << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}