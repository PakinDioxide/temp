#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n, m, k;
    cin >> n >> m >> k;
    vector <pair <ll, ll>> adj[n];
    for (ll i = 0, u, v, w; i < m; i++) cin >> u >> v >> w, adj[u].emplace_back(v, w), adj[v].emplace_back(u, w);
    ll dp[n][k+1], mx[n][k+1];
    for (ll i = 0; i < n; i++) for (ll j = 0; j <= k; j++) dp[i][j], mx[i][j] = LLONG_MAX;
    for (ll i = 0; i <= k; i++) dp[0][i] = mx[0][i] = 1;
    priority_queue <pair <ll, ll>> q;
    q.emplace(0, 0);
    while (!q.empty()) {
        ll u = q.top().second;
        q.pop();
        for (ll i = 1; i <= k; i++) if (mx[u][i] > mx[u][i-1]) mx[u][i] = mx[u][i-1], dp[u][i] = dp[u][i-1];
        for (auto [v, w] : adj[u]) {
            ll ok = 0;
            for (ll i = k; i >= 0; i--) {
                ll kk = 0;
                if (dp[v][i] > dp[u][i] + w) dp[v][i] = dp[u][i] + w, mx[v][i] = max(mx[u][i], dp[u][i] + w), kk = 1;
                else if (dp[v][i] == dp[u][i] + w && max(mx[u][i], dp[u][i] + w) < mx[v][i]) dp[v][i] = dp[u][i] + w, mx[v][i] = max(mx[u][i], dp[u][i] + w), kk = 1;
                if (i > 0) {
                    if (dp[v][i] > dp[u][i-1]) dp[v][i] = dp[u][i-1] - w, mx[v][i] = max(mx[u][i-1], dp[u][i-1] - w), kk = 1;
                    else if (dp[v][i] == dp[u][i-1] && max(mx[u][i-1], dp[u][i-1] - w) < mx[v][i]) dp[v][i] = dp[u][i-1] - w, mx[v][i] = max(mx[u][i-1], dp[u][i-1] - w), kk = 1;
                }
                // if (max(mx[u][i], dp[u][i] + w) < mx[v][i]) dp[v][i] = dp[u][i] + w, mx[v][i] = max(mx[u][i], dp[u][i] + w), kk = 1;
                // else if (max(mx[u][i], dp[u][i] + w) == mx[v][i] && dp[v][i] > dp[u][i] + w) dp[v][i] = dp[u][i] + w, mx[v][i] = max(mx[u][i], dp[u][i] + w), kk = 1;
                // if (i > 0) {
                //     if (max(mx[u][i-1], dp[u][i-1] - w) < mx[v][i]) dp[v][i] = dp[u][i-1] - w, mx[v][i] = max(mx[u][i-1], dp[u][i-1] - w), kk = 1;
                //     // else if (max(mx[u][i-1], dp[u][i-1] - w) == mx[v][i] && dp[v][i] > dp[u][i-1] - w) dp[v][i] = dp[u][i-1] - w, mx[v][i] = max(mx[u][i-1], dp[u][i-1] - w), kk = 1;
                // }
                // if (kk && !ok) ok = 1, q.emplace(-mx[v][i], v);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << i << '\n';
        cout << "A ";
        for (int j = 0; j <= k; j++) cout << dp[i][j] << ' ';
        cout << '\n';
        cout << "B ";
        for (int j = 0; j <= k; j++) cout << mx[i][j] << ' ';
        cout << '\n';
    }

    ll ans = LLONG_MAX;
    for (int i = 0; i <= k; i++) ans = min(ans, mx[n-1][i]);
    cout << ans;
}