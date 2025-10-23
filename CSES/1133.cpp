/*
    author  : PakinDioxide
    created : 03/05/2025 21:34
    task    : 1133
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;

ll n, ans[mxN], dp[mxN], cnt[mxN];
vector <int> adj[mxN];

void dfs1(int u, int p) {
    cnt[u] = 1;
    for (auto v : adj[u]) if (v != p) {
        dfs1(v, u);
        dp[u] += dp[v] + cnt[v];
        cnt[u] += cnt[v];
    }
}

void dfs2(int u, int p, ll up) {
    ans[u] = dp[u] + up;
    for (auto v : adj[u]) if (v != p) {
        dfs2(v, u, ans[u] - (dp[v] + cnt[v]) + (n - cnt[v]));
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1, u, v; i < n; i++) cin >> u >> v, adj[u].emplace_back(v), adj[v].emplace_back(u);
    dfs1(1, 1);
    dfs2(1, 1, 0);
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';
}