/*
    author  : PakinDioxide
    created : 15/04/2025 14:57
    task    : 1472G
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;
vector <int> adj[mxN], adjt[mxN];
int n, m, dis[mxN], dp[mxN][2];

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) dis[i] = dp[i][0] = dp[i][1] = INT_MAX, adj[i].clear(), adjt[i].clear();
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adjt[v].emplace_back(u);
    }
    dis[1] = 0;
    queue <pair <int, int>> q;
    q.emplace(0, 1);
    while (!q.empty()) {
        auto [w, u] = q.front();
        q.pop();
        if (dis[u] != w) continue;
        for (auto v : adj[u]) if (dis[v] > w+1) q.emplace(dis[v] = w+1, v);
    }
    priority_queue <tuple <int, int, int>> Q;
    for (int i = 1; i <= n; i++) dp[i][0] = dp[i][1] = dis[i], Q.emplace(-dp[i][0], i, 0);
    while (!Q.empty()) {
        auto [w, u, c] = Q.top(); w=-w;
        Q.pop();
        if (dp[u][c] != w) continue;
        for (auto v : adjt[u]) {
            if (dis[v] < dis[u]) { if (dp[v][c] > dp[u][c]) Q.emplace(-(dp[v][c] = dp[u][c]), v, c); }
            else { if (c == 0 && dp[v][1] > dp[u][0]) Q.emplace(-(dp[v][1] = dp[u][0]), v, 1); }
        }
    }
    for (int i = 1; i <= n; i++) cout << min(dp[i][0], dp[i][1]) << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}