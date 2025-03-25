/*
    author  : PakinDioxide
    created : 23/03/2025 11:57
    task    : 2018_Jan_S_3
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    vector <pair <int, int>> adj[n+1];
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    while (q--) {
        int k, u, cnt = 0;
        cin >> k >> u;
        queue <tuple <int, int, int>> q;
        q.emplace(INT_MAX, u, u);
        while (!q.empty()) {
            auto [w, u, p] = q.front();
            q.pop();
            if (w < k) continue;
            cnt++;
            for (auto [v, ww] : adj[u]) {
                if (v == p) continue;
                q.emplace(min(w, ww), v, u);
            }
        }
        cout << cnt-1 << '\n';
    }
}