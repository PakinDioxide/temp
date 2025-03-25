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
    ll mx = -1, idx = 0, ans = 0, vis[n+1];
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) if (h[i] > mx) mx = h[i], idx = i;
    priority_queue <tuple <ll, ll, ll, int>> q;
    q.emplace(0, 0, -h[idx], idx);
    while (!q.empty()) {
        auto [k, w, H, u] = q.top();
        w=-w;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        ans += w;
        // cout << ans << ' ' << w << ' ' << k << ' ' << u << '\n';
        for (int v : adj[u]) {
            if (vis[v]) continue;
            if (h[v] <= h[u]) q.emplace(k + h[u] - h[v], -h[u], -h[v], v);
            else q.emplace(max(0LL, k - (h[v] - h[u])), -(h[u] + max(0LL, (h[v] - h[u]) - k)), -h[v], v);
        }
    }
    cout << ans << '\n';
}