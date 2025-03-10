#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    ll h[n+1];
    for (int i = 1; i <= n; i++) cin >> h[i];
    vector <int> adj[n+1];
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll mx = 0, idx = 0, ans = 0, vis[n+1];
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) if (h[i] > mx) mx = h[i], idx = i;
    priority_queue <tuple <ll, ll, ll, int>> q;
    q.emplace(-h[idx], 0, 0, idx);
    while (!q.empty()) {
        auto [H, w, k, u] = q.top();
        w=-w;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        ans += w;
        // cout << ans << ' ' << w << ' ' << k << ' ' << u << '\n';
        for (int v : adj[u]) {
            if (vis[v]) continue;
            if (h[v] <= h[u]) q.emplace(-h[v], -h[u], k + h[u] - h[v], v);
            else q.emplace(-h[v], -(h[u] + max(0LL, (h[v] - h[u]) - k)), max(0LL, k - (h[v] - h[u])), v);
        }
    }
    cout << ans << '\n';
}