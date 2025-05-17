/*
    author  : PakinDioxide
    created : 08/05/2025 17:13
    task    : 919D
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 3e5+5;

int n, m, a[mxN], deg[mxN], dp[mxN][26], mx = 0;
vector <int> adj[mxN], adjt[mxN], tp;
queue <int> q;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) { char c; cin >> c; a[i] = c-'a'; }
    for (int i = 0, u, v; i < m; i++) cin >> u >> v, adj[u].emplace_back(v), adjt[v].emplace_back(u), deg[u]++;
    for (int i = 1; i <= n; i++) if (!deg[i]) q.emplace(i);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        tp.emplace_back(u);
        for (auto v : adjt[u]) if (!(--deg[v])) q.emplace(v);
    }
    if (tp.size() != n) { cout << -1 << '\n'; return 0; }
    for (auto &u : tp) {
        for (auto &v : adj[u]) for (int i = 0; i < 26; i++) dp[u][i] = max(dp[u][i], dp[v][i]);
        dp[u][a[u]]++;
    }
    for (int i = 1; i <= n; i++) for (int j = 0; j < 26; j++) mx = max(mx, dp[i][j]);
    cout << mx << '\n';
}