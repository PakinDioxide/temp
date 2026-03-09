#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m; cin >> n >> m;
    int dis[n+1]; memset(dis, 0, sizeof(dis));
    vector <pair <int, int>> adj[n+1];
    for (int i = 0; i < n; i++) adj[i].emplace_back(i+1, 0), adj[i+1].emplace_back(i, -1);
    while (m--) {
        int l, r, k, v; cin >> l >> r >> k >> v;
        r++;
        if (v == 1) adj[r].emplace_back(l, -(k-1));
        else adj[l].emplace_back(r, k);
    }
    for (int c = 0; c < n; c++) {
        for (int u = 0; u <= n; u++) {
            for (auto [v, w] : adj[u]) dis[v] = max(dis[v], dis[u] + w);
        }
    }
    for (int u = 0; u <= n; u++) {
        for (auto [v, w] : adj[u]) if (dis[v] < dis[u] + w) { cout << -1 << '\n'; return 0; }
    }
    for (int i = 1; i <= n; i++) cout << !(dis[i] - dis[i-1]) << ' '; cout << '\n';
}

/*
R - L <= x
-x <= L - R
L - R >= -x

R - L >= x
*/