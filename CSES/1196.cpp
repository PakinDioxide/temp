/*
    author  : PakinDioxide
    created : 24/03/2025 13:23
    task    : 1196
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector <pair <int, ll>> adj[n+1];
    for (int i = 0; i < m; i++) {
        int u, v; ll w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }
    priority_queue <ll> dis[n+1];
    dis[1].push(0);
    priority_queue <pair <ll, int>> q;
    q.emplace(0, 1);
    while (!q.empty()) {
        auto [w, u] = q.top();
        q.pop();
        w=-w;
        if (w > dis[u].top()) continue;
        for (auto [v, ww] : adj[u]) {
            if (dis[v].size() < k) {
                dis[v].push(ww+w);
                q.emplace(-(ww+w), v);
            } else if (dis[v].top() > w+ww) {
                dis[v].push(ww+w);
                dis[v].pop();
                q.emplace(-(ww+w), v);
            }
        }
    }
    vector <ll> ans;
    while (!dis[n].empty()) ans.push_back(dis[n].top()), dis[n].pop();
    for (int i = k-1; i >= 0; i--) cout << ans[i] << ' ';
    cout << '\n';
}