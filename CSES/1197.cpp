/*
    author  : PakinDioxide
    created : 11/03/2025 20:26
    task    : 1197
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <tuple <int, int, ll>> E(m);
    for (auto &[u, v, w] : E) cin >> u >> v >> w;
    ll dis[n+1], p[n+1], vis[n+1];
    for (int i = 1; i <= n; i++) dis[i] = 1e18, p[i] = i, vis[i] = 0;
    dis[1] = 0;
    for (int i = 0; i < n-1; i++) {
        for (auto [u, v, w] : E) {
            if (dis[v] > dis[u] + w) dis[v] = dis[u] + w, p[v] = u;
        }
    }
    int cng = 0, idx = 0;
    for (auto [u, v, w] : E) {
        if (dis[v] > dis[u] + w) {cng = 1; idx = u; p[v] = u; dis[v] = dis[u] + w;}
    }
    if (!cng) {cout << "NO\n"; return 0;}
    cout << "YES\n";
    for (int i = 0; i < n; i++) idx = p[idx];
    stack <int> ans;
    while (!vis[idx]) ans.push(idx), vis[idx] = 1, idx = p[idx];
    cout << idx << ' ';
    while (!ans.empty()) cout << ans.top() << ' ', ans.pop();
    cout << '\n';
}