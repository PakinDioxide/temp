#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    vector <int> adj[n+1], V;
    for (int i = 1, u, v; i < n; i++) cin >> u >> v, adj[u].emplace_back(v), adj[v].emplace_back(u);
    queue <pair <int, int>> q;
    q.emplace(1, 1);
    while (!q.empty()) {
        auto [u, p] = q.front(); q.pop();
        V.emplace_back(u);
        for (auto v : adj[u]) if (v != p) q.emplace(v, u);
    }
    vector <tuple <int, int, int>> a(n);
    for (int i = 0; i < n; i++) {
        auto &[x, y, idx] = a[i];
        cin >> x >> y; idx = i;
    }
    sort(a.begin(), a.end());
    int ans[n+1];
    for (int i = 0; i < n; i++) ans[get<2>(a[i])] = V[i];
    for (int i = 0; i < n; i++) cout << ans[i] << ' '; cout << '\n';
}
