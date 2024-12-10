#include <bits/stdc++.h>

using namespace std;

int dp[101][101][2];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, s, d, f, m;
    cin >> n;
    int price[n+1];
    for (int i = 1; i <= n; i++) {
        cin >> price[i];
        for (int j = 0; j <= 100; j++) dp[i][j][0] = dp[i][j][1] = INT_MAX;
    }
    cin >> s >> d >> f >> m;
    vector <pair <int, int>> adj[n+1];
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    priority_queue <pair <int, int>> q;
    q.emplace(0, s);
    dp[s][0][0] = dp[s][0][1] = 0;
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        for (int i = 1; i <= f; i++) {
            dp[u][i][0] = min(dp[u][i][0], dp[u][i-1][0] + price[u]);
            dp[u][i][1] = min({dp[u][0][0], dp[u][i][1], dp[u][i-1][1] + price[u]});
        }
        for (auto o : adj[u]) {
            int v = o.first, w = o.second;
            int l = 0, r = 0;
            for (int i = w; i <= f; i++) {
                if (dp[v][i-w][0] > dp[u][i][0]) {
                    dp[v][i-w][0] = dp[u][i][0];
                    if (!l) {q.emplace(-dp[v][i-w][0], v); l = 1;}
                }
                if (dp[v][i-w][1] > dp[u][i][1]) {
                    dp[v][i-w][1] = dp[u][i][1];
                    if (!r) {q.emplace(-dp[v][i-w][1], v); r = 1;}
                }
            }
        }
    }
    cout << dp[d][f][1];
}