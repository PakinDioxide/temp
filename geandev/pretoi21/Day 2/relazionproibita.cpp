#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;

ll n, dp[mxN][2], val[4], t[mxN];
vector <int> adj[mxN];

void dfs(int u, int p) {
    dp[u][1] = val[t[u]];
    if (t[u] == 0) {
        for (auto v : adj[u]) if (v != p) {
            dfs(v, u);
            dp[u][0] += max(dp[v][0], dp[v][1]);
            dp[u][1] += max(dp[v][0], dp[v][1]);
        }
    } else if (t[u] == 1) {
        for (auto v : adj[u]) if (v != p) {
            dfs(v, u);
            dp[u][0] += max(dp[v][0], dp[v][1]);
            if (t[v] == 0 || t[v] == 3) dp[u][1] += max(dp[v][0], dp[v][1]);
            else dp[u][1] += dp[v][0];
        }
    } else if (t[u] == 2) {
        for (auto v : adj[u]) if (v != p) {
            dfs(v, u);
            dp[u][0] += max(dp[v][0], dp[v][1]);
            if (t[v] == 0) dp[u][1] += max(dp[v][0], dp[v][1]);
            else dp[u][1] += dp[v][0];
        }
    } else {
        for (auto v : adj[u]) if (v != p) {
            dfs(v, u);
            dp[u][0] += max(dp[v][0], dp[v][1]);
            if (t[v] == 0) dp[u][1] += max(dp[v][0], dp[v][1]);
            else dp[u][1] += dp[v][0];
        }
    }
}

int main() {
    cin >> n >> val[1] >> val[2] >> val[3];
    for (int i = 1; i <= n; i++) cin >> t[i];
    for (int i = 1, u, v; i < n; i++) cin >> u >> v, adj[u].emplace_back(v), adj[v].emplace_back(u);
    dfs(1, 1);
    cout << max(dp[1][0], dp[1][1]) << '\n';
}

/*
8
1 4 3
0 3 0 2 1 1 0 3
1 2
1 3
1 4
4 6
1 5
5 8
5 7
*/