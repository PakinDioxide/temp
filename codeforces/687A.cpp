/*
    author  : 
    created : 27/08/2025 08:27
    task    : 687A
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;

int n, m, c[mxN];
vector <int> adj[mxN], C[2];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 0, u, v; i < m; i++) cin >> u >> v, adj[u].emplace_back(v), adj[v].emplace_back(u);
    queue <int> q;
    for (int i = 1; i <= n; i++) if (!c[i]) {
        q.emplace(i);
        c[i] = 1;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            C[c[u]-1].emplace_back(u);
            for (auto v : adj[u]) {
                if (c[v] && c[v] == c[u]) { cout << -1 << '\n'; return 0; }
                else if (c[v]) continue;
                c[v] = (c[u] == 1 ? 2 : 1);
                q.emplace(v);
            }
        }
    }
    if (C[0].empty() || C[1].empty()) { cout << -1 << '\n'; return 0; }
    cout << C[0].size() << '\n';
    for (auto &e : C[0]) cout << e << ' '; cout << '\n';
    cout << C[1].size() << '\n';
    for (auto &e : C[1]) cout << e << ' '; cout << '\n';
}