/*
    author  : PakinDioxide
    created : 16/03/2025 18:46
    task    : D2_A
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, k, s, t;
    cin >> n >> m >> k >> s >> t;
    k++;
    vector <tuple <int, ll, int>> adj[n+1];
    ll p[k], sell[n+1][k];
    for (int i = 0; i < m; i++) {
        int u, v, c; ll w;
        cin >> u >> v >> w >> c;
        adj[u].emplace_back(v, w, c);
        adj[v].emplace_back(u, w, c);
    }
    for (int i = 1; i < k; i++) cin >> p[i];
    memset(sell, 0, sizeof(sell));
    for (int i = 1; i < k; i++) {
        int cnt, x;
        cin >> cnt;
        for (int j = 0; j < cnt; j++) cin >> x, sell[x][i] = 1;
    }
    ll dis[n+1][(1 << k)], vis[n+1][(1 << k)];
    for (int i = 0; i <= n; i++) for (int j = 0; j < (1 << k); j++) dis[i][j] = LLONG_MAX, vis[i][j] = 0;
    dis[s][0] = 0;
    priority_queue <tuple <ll, int , int, int>> q;
    q.emplace(0, s, 0, -1);
    while (!q.empty()) {
        int u = get<1>(q.top()), pass = get<2>(q.top()), par = get<3>(q.top());
        q.pop();
        if (vis[u][pass]) continue;
        vis[u][pass] = 1;
        // if (u == t || 1) cout << "FORW : " << u << ' ' << par << ' ' << pass << ' ' << dis[u][pass] << '\n';
        // no buy pass
        for (auto[v, w, c] : adj[u]) {
            if (dis[v][pass] > dis[u][pass] + ((pass & (1 << c)) ? 0 : w)) {
                dis[v][pass] = dis[u][pass] + ((pass & (1 << c)) ? 0 : w);
                q.emplace(-dis[v][pass], v, pass, u);
            }
        }
        // buy pass
        for (int i = 1; i < k; i++) {
            if (!sell[u][i] || (pass & (1 << i))) continue;
            int p2 = pass | (1 << i);
            if (dis[u][p2] > dis[u][pass] + p[i]) {
                dis[u][p2] = dis[u][pass] + p[i];
                q.emplace(-dis[u][p2], u, p2, u);
            }
            // for (auto [v, w, c] : adj[u]) {
            //     if (dis[v][p2] > dis[u][pass] + ((p2 & (1 << c)) ? 0 : w) + p[i]) {
            //         dis[v][p2] = dis[u][pass] + ((p2 & (1 << c)) ? 0 : w) + p[i];
            //         q.emplace(-dis[v][p2], v, p2);
            //     }
            // }
        }
    }

    // go back
    ll dis2[n+1][(1 << k)], vis2[n+1][(1 << k)];
    for (int i = 0; i <= n; i++) for (int j = 0; j < (1 << k); j++) dis2[i][j] = LLONG_MAX, vis2[i][j] = 0;
    for (int j = 0; j < (1 << k); j++) if (dis[t][j] != LLONG_MAX) dis2[t][j] = dis[t][j], q.emplace(-dis2[t][j], t, j, -1);
    while (!q.empty()) {
        int u = get<1>(q.top()), pass = get<2>(q.top()), par = get<3>(q.top());
        q.pop();
        if (vis2[u][pass]) continue;
        vis2[u][pass] = 1;
        // if (u == s) cout << "BACK : " << u << ' ' << par << ' ' << pass << ' ' << dis[u][pass] << '\n';
        // no buy pass
        for (auto [v, w, c] : adj[u]) {
            if (dis2[v][pass] > dis2[u][pass] + ((pass & (1 << c)) ? 0 : w)) {
                dis2[v][pass] = dis2[u][pass] + ((pass & (1 << c)) ? 0 : w);
                q.emplace(-dis2[v][pass], v, pass, u);
            }
        }
        // buy pass
        for (int i = 1; i < k; i++) {
            if (!sell[u][i] || (pass & (1 << i))) continue;
            int p2 = pass | (1 << i);
            if (dis2[u][p2] > dis2[u][pass] + p[i]) {
                dis2[u][p2] = dis2[u][pass] + p[i];
                q.emplace(-dis2[u][p2], u, p2, u);
            }
            // if (!sell[u][i] || (pass & (1 << i))) continue;
            // int p2 = pass | (1 << i);
            // for (auto[v, w, c] : adj[u]) {
            //     if (dis2[v][p2] > dis2[u][pass] + ((p2 & (1 << c)) ? 0 : w) + p[i]) {
            //         dis2[v][p2] = dis2[u][pass] + ((p2 & (1 << c)) ? 0 : w) + p[i];
            //         q.emplace(-dis2[v][p2], v, p2);
            //     }
            // }
        }
    }
    ll ans = LLONG_MAX;
    for (int j = 0; j < (1 << k); j++) ans = min(ans, dis2[s][j]);//, cout << j << ' ' << dis2[s][j] << ' ' << '\n';
    cout << ans << '\n';
    cout << 0 << '\n';
}

/*
can we do the dijkstra from s -> t first
then push the dist to the array
then dijkstra back from t -> s
*/