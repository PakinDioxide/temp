#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 3e5+5;

int n, m, id[mxN], it = 0, dp[mxN];
vector <pair <int, int>> adj[mxN];
pair <int, int> ans[mxN];

void dfs(int u, int p) {
    id[u] = ++it;
    for (auto [v, idx] : adj[u]) if (v != p) {
        if (id[v]) {
            if (id[v] > id[u]) dp[u]--;
            else dp[u]++, ans[idx] = make_pair(u, v);
        } else dfs(v, u), dp[u] += dp[v], ans[idx] = make_pair(u, v);
    }
    if (u != 1 && dp[u] == 0) { cout << 0 << '\n'; exit(0); }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 0, u, v; i < m; i++) cin >> u >> v, adj[u].emplace_back(v, i), adj[v].emplace_back(u, i);
    dfs(1, 1);
    for (int i = 0; i < m; i++) cout << ans[i].first << ' ' << ans[i].second << '\n';
}
