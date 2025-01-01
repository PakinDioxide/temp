#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    int c[n+1], s, d, f, m;
    for (int i = 1; i <= n; i++) cin >> c[i];
    cin >> s >> d >> f >> m;
    vector <pair <int, int>> adj[n+1];
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    ll dp[n+1][f+1][2];
    for (int i = 1; i <= n; i++) for (int j = 0; j <= f; j++) dp[i][j][0] = dp[i][j][1] = LLONG_MAX;
    dp[s][0][0] = dp[s][0][1] = 0;
    priority_queue <pair <int, int>> q;
    q.emplace(0, s);
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        for (int i = 1; i <= f; i++) {
            dp[u][i][0] = min(dp[u][i][0], dp[u][i-1][0] + c[u]);
            dp[u][i][1] = min({dp[u][i][1], dp[u][0][0], dp[u][i-1][1] + c[u]});
        }
        for (auto [v, w] : adj[u]) {
            int ok = 0;
            for (int i = w; i <= f; i++) {
                if (dp[v][i-w][0] > dp[u][i][0]) {
                    dp[v][i-w][0] = dp[u][i][0];
                    if (!ok) q.emplace(-dp[v][i][0], v);
                    ok = 1;
                }
                if (dp[v][i-w][1] > dp[u][i][1]) {
                    dp[v][i-w][1] = dp[u][i][1];
                    if (!ok) q.emplace(-dp[v][i][1], v);
                    ok = 1;
                }
            }
        }
    }
    ll ans = min(dp[d][f][0], dp[d][f][1]);
    cout << (ans == LLONG_MAX ? -1 : ans);
}