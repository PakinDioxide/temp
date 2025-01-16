#include <bits/stdc++.h>
#define ll int

using namespace std;

int main() {
    // ios::sync_with_stdio(0), cin.tie(0);
    ll n, m, k;
    cin >> n >> m >> k;
    vector <pair <ll, ll>> adj[n];
    for (ll i = 0, u, v, w; i < m; i++) cin >> u >> v >> w, adj[u].emplace_back(v, w), adj[v].emplace_back(u, w);
    queue <tuple <ll, ll, ll, ll, ll>> q;
    ll dp[n][k+1];
    ll ans = INT_MAX;
    for (int i = 0; i < n; i++) for (int j = 0; j <= k; j++) dp[i][j] = INT_MAX;
    for (int i = 0; i <= k; i++) dp[0][i] = 0;
    q.emplace(0, 0, 0, 0, -1);
    int st = 0;
    while (!q.empty()) {
        auto [u, w, mx, cnt, p] = q.front();
        // cout << u << ' ' << w << ' ' << mx << ' ' << cnt << ' ' << p << '\n';
        q.pop();
        if (u == n-1) ans = min(ans, mx);
        if (mx >= dp[u][cnt] && st) continue;
        dp[u][cnt] = mx;
        st = 1;
        // if (vis[u][cnt]) continue;
        // vis[u][cnt] = 1;
        for (auto [v, ww] : adj[u]) {
            if (v != p && u != n-1 && dp[v][cnt] > max(mx, w+ww)) q.emplace(v, w+ww, max(mx, w+ww), cnt, u);
            if (cnt < k && dp[v][cnt] > max(mx, w-ww)) q.emplace(v, w-ww, max(mx, w-ww), cnt+1, u);
        }
    }
    cout << ans+1;
}