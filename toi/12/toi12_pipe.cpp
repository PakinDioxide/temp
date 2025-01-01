#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n >> k;
    int a[n][2], vis[n];
    vector <pair <int, int>> adj[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
        vis[i] = 0;
        for (int j = 0; j < i; j++) adj[i].emplace_back(j, abs(a[i][0] - a[j][0]) + abs(a[i][1] - a[j][1])), adj[j].emplace_back(i, abs(a[i][0] - a[j][0]) + abs(a[i][1] - a[j][1]));
    }
    priority_queue <pair <int, int>> q;
    q.emplace(0, 0);
    vector <int> ans;
    while (!q.empty() && ans.size() < n-1) {
        auto [w, u] = q.top();
        q.pop();
        w=-w;
        if (vis[u]) continue;
        vis[u] = 1;
        if (w > 0) ans.push_back(w);
        for (auto [v, ww] : adj[u]) {
            if (!vis[v]) q.emplace(-ww, v);
        }
    }
    sort(ans.begin(), ans.end());
    int mst = 0;
    for (int i = 0; i < n-k; i++) mst += ans[i];
    cout << mst << '\n';
}