/*
    author  : PakinDioxide
    created : 07/04/2025 03:17
    task    : 1678
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MX = 1e5+5;

int vis[MX], rvis[MX], dp[MX], n, m;
vector <int> adj[MX];

void dfs(int u) {
    rvis[u] = 1;
    for (auto v : adj[u]) {
        if (rvis[v] && !vis[v]) {dp[u] = v; break;}
        if (!vis[v]) dfs(v);
        if (dp[v] > 0) dp[u] = v;
    }
    rvis[u] = 0;
    vis[u] = 1;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
    }
    for (int i = 1; i <= n; i++) if (!vis[i]) {
        dfs(i);
        if (dp[i] == 0) continue;
        memset(vis, 0, sizeof(vis));
        int k = i;
        deque <int> ans;
        while (!vis[k]) ans.emplace_back(k), vis[k] = 1, k = dp[k];
        ans.emplace_back(k);
        while (ans.front() != k) ans.pop_front();
        cout << ans.size() << '\n';
        for (auto &e : ans) cout << e << ' ';
        cout << '\n';
        return 0;
    }
    cout << "IMPOSSIBLE\n";
}