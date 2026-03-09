#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e4+5;
const int INF = 1e9;

int sz[mxN];
vector <pair <int, int>> adj[mxN];
int dp[mxN][2][mxN];

void dfs(int u, int p) {
    sz[u] = 1;
    for (auto [v, w] : adj[u]) if (v != p) {
        dfs(v, u);
        for (int i = sz[u]; i >= 0; i--) for (int j = sz[v]; j >= 0; j--) {
            dp[u][1][i+j] = min({dp[u][1][i+j], dp[u][1][i] + dp[v][0][j] + 2*w, dp[u][0][i] + dp[v][1][j] + w});
            dp[u][0][i+j] = min(dp[u][0][i+j], dp[u][0][i] + dp[v][0][j] + 2*w);
        }
        sz[u] += sz[v];
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, k, x;
    cin >> n >> k >> x;
    for (int i = 1; i < n; i++) {
        int u, v; int w; cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    for (int i = 1; i <= n; i++) for (int j = 2; j <= n; j++) dp[i][0][j] = dp[i][1][j] = INF;
    dfs(x, x);
    cout << dp[x][1][k] << '\n';
}

