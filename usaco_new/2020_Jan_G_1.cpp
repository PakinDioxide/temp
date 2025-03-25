/*
    author  : PakinDioxide
    created : 24/03/2025 16:01
    task    : 2020_Jan_G_1
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);
    int n, m, c;
    cin >> n >> m >> c;
    int a[n+1], mx = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], mx = max(mx, a[i]);
    vector <int> adj[n+1];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
    }
    int dmx = 0;
    for (; c*((dmx+1)*(dmx+1) - dmx*dmx) <= mx; dmx++);
    int dp[n+1][dmx+1];
    for (int i = 1; i <= n; i++) for (int j = 0; j <= dmx; j++) dp[i][j] = INT_MIN;
    dp[1][0] = 0;
    for (int i = 0; i < dmx; i++) {
        for (int u = 1; u <= n; u++) {
            for (auto v : adj[u]) {
                dp[v][i+1] = max(dp[v][i+1], dp[u][i] + a[v]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= dmx; i++) if (dp[1][i] > 0) ans = max(ans, dp[1][i] - c*i*i);
    cout << ans << '\n';
}