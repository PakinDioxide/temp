/*
    author  : PakinDioxide
    created : 18/04/2025 20:56
    task    : 724
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;

int n, m, q, dis[2][mxN], ok[mxN];
vector <int> adj[2][mxN], ans;
vector <pair <int, int>> Q;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[0][u].emplace_back(v);
        adj[1][v].emplace_back(u);
    }
    Q.resize(q);
    for (auto &[t, x] : Q) cin >> t >> x, ok[x] = (t == 1 ? 1 : ok[x]);
    reverse(Q.begin(), Q.end());
    auto bfs = [&] (int x, int k) {
        queue <int> q;
        q.emplace(x);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (ok[u] || !dis[k][u]) continue;
            for (auto v : adj[k][u]) if (!dis[k][v]) q.emplace(v), dis[k][v] = 1;
        }
    };
    dis[0][1] = 1, dis[1][n] = 1;
    bfs(1, 0), bfs(n, 1);
    for (auto &[t, x] : Q) {
        if (t == 1) {
            ok[x] = 0;
            bfs(x, 0), bfs(x, 1);
        } else ans.emplace_back(dis[0][x] && dis[1][x] && !ok[x]);
    }
    reverse(ans.begin(), ans.end());
    for (auto &e : ans) cout << e << '\n';
}