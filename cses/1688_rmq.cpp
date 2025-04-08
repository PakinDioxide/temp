/*
    author  : PakinDioxide
    created : 08/04/2025 02:07
    task    : 1688_rmq
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;
int n, q, dep[mxN], idx[mxN];
vector <int> adj[mxN];
vector <pair <int, int>> euler, dp[20];

void dfs(int u) {
    euler.emplace_back(dep[u], u);
    idx[u] = euler.size()-1;
    for (auto v : adj[u]) dep[v] = dep[u] + 1, dfs(v), euler.emplace_back(dep[u], u);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i = 2; i <= n; i++) { int x; cin >> x; adj[x].emplace_back(i); }
    dfs(1);
    for (int i = 0; i < 20; i++) dp[i].resize(euler.size());
    for (int i = 0; i < euler.size(); i++) dp[0][i] = euler[i];
    for (int i = 1; i < 20; i++) for (int j = 0; j + (1 << i) <= euler.size(); j++) dp[i][j] = min(dp[i-1][j], dp[i-1][j + (1 << (i-1))]);
    while (q--) {
        int u, v;
        cin >> u >> v;
        u = idx[u], v = idx[v];
        if (u > v) swap(u, v);
        v++;
        int d = v-u;
        pair <int, int> ans = {INT_MAX, -1};
        for (int i = 0; i < 20; i++) if (d & (1 << i)) ans = min(ans, dp[i][u]), u += (1 << i);
        cout << ans.second << '\n';
    }
}