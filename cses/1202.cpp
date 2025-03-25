/*
    author  : PakinDioxide
    created : 25/03/2025 14:33
    task    : 1202
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <pair <int, ll>> adj[n+1];
    ll mod = 1e9+7;
    for (int i = 0; i < m; i++) {
        int u, v; ll w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }
    ll dis[n+1], k[n+1][2], cnt[n+1];
    for (int i = 1; i <= n; i++) dis[i] = LLONG_MAX, k[i][0] = k[i][1] = 0, cnt[i] = 0;
    priority_queue <pair <ll, int>> q;
    dis[1] = k[1][0] = k[1][1] = 0;
    cnt[1] = 1;
    q.emplace(0, 1);
    while (!q.empty()) {
        auto [w, u] = q.top();
        w=-w;
        q.pop();
        if (dis[u] != w) continue;
        for (auto [v, ww] : adj[u]) {
            if (dis[v] > w+ww) {
                dis[v] = w+ww;
                k[v][0] = k[u][0]+1;
                k[v][1] = k[u][1]+1;
                cnt[v] = cnt[u];
                q.emplace(-dis[v], v);
            } else if (dis[v] == w+ww) {
                k[v][0] = min(k[v][0], k[u][0]+1);
                k[v][1] = max(k[v][1], k[u][1]+1);
                cnt[v] += cnt[u];
            }
            cnt[v] %= mod;
        }
    }
    cout << dis[n] << ' ' << cnt[n] << ' ' << k[n][0] << ' ' << k[n][1] << '\n';
}