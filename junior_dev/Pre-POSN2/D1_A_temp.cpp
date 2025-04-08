/*
    author  : PakinDioxide
    created : 08/04/2025 12:31
    task    : D1_A_temp
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;

int n, m, t, deg[mxN], s[3][mxN], dps[mxN][2], dp[mxN][2], dpe[mxN][2], st[mxN];
vector <int> adj[mxN], adjr[mxN], topo, ans;
queue <int> q;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> t;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adjr[v].emplace_back(u);
        deg[u]++;
    }
    for (int i = 0; i < 3; i++) for (int j = 1; j <= n; j++) cin >> s[i][j];
    for (int i = 1; i <= n; i++) if (!deg[i]) q.emplace(i);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo.emplace_back(u);
        for (auto v : adjr[u]) if (--deg[v] == 0) q.emplace(v);
    }
    for (int i = 1; i <= n; i++) dp[i][0] = dp[i][1] = dpe[i][0] = dpe[i][1] = dps[i][0] = dps[i][1] = INT_MIN;
    for (auto &u : topo) {
        if (u == t) st[u] = 1, dps[u][0] = 0;
        // if (s[1][u]) st[u] = 2, dp[u][0] = dps[u][0], dp[u][1] = dps[u][1];
        // cout << u << '\n';
        for (auto &v : adj[u]) {
            if (dp[v][0] >= dp[u][0]) dp[u][1] = dp[u][0], dp[u][0] = dp[v][0];
            else if (dp[v][0] >= dp[u][1]) dp[u][1] = dp[v][0];
            if (dp[v][1] >= dp[u][0]) dp[u][1] = dp[u][0], dp[u][0] = dp[v][1];
            else if (dp[v][1] >= dp[u][1]) dp[u][1] = dp[v][1];
            if (dps[v][0] >= dps[u][0]) dps[u][1] = dps[u][0], dps[u][0] = dps[v][0];
            else if (dps[v][0] >= dps[u][1]) dps[u][1] = dps[v][0];
            if (dps[v][1] >= dps[u][0]) dps[u][1] = dps[u][0], dps[u][0] = dps[v][1];
            else if (dps[v][1] >= dps[u][1]) dps[u][1] = dps[v][1];
            if (dpe[v][0] >= dpe[u][0]) dpe[u][1] = dpe[u][0], dpe[u][0] = dpe[v][0];
            else if (dpe[v][0] >= dpe[u][1]) dpe[u][1] = dpe[v][0];
            if (dpe[v][1] >= dpe[u][0]) dpe[u][1] = dpe[u][0], dpe[u][0] = dpe[v][1];
            else if (dpe[v][1] >= dpe[u][1]) dpe[u][1] = dpe[v][1];
        }
        if (s[1][u]) {
            if (dps[u][0] >= dp[u][0]) dp[u][1] = dp[u][0], dp[u][0] = dps[u][0];
            else if (dps[u][0] >= dp[u][1]) dp[u][1] = dps[u][0];
            if (dps[u][1] >= dp[u][0]) dp[u][1] = dp[u][0], dp[u][0] = dps[u][1];
            else if (dps[u][1] >= dp[u][1]) dp[u][1] = dps[u][1];
        }
        //if (st[u] == 2) 
        for (int i = 0; i < 2; i++) if (dp[u][i] > INT_MIN) dp[u][i] += s[2][u];
        // cout << dp[u][0] << ' ' << dp[u][1] << '\n';
        // cout << dps[u][0] << ' ' << dps[u][1] << '\n';
        if (s[0][u]) {
            if (dp[u][0] >= dpe[u][0]) dpe[u][1] = dpe[u][0], dpe[u][0] = dp[u][0];
            else if (dp[u][0] >= dpe[u][1]) dpe[u][1] = dp[u][0];
            if (dp[u][1] >= dpe[u][0]) dpe[u][1] = dpe[u][0], dpe[u][0] = dp[u][1];
            else if (dp[u][1] >= dpe[u][1]) dpe[u][1] = dp[u][1];
        }
        for (int i = 0; i < 2; i++) if (dpe[u][i] > INT_MIN) ans.emplace_back(dpe[u][i]);
    }
    sort(ans.begin(), ans.end());
    // for (auto &e : ans) cout << e << ' ';
    // cout << '\n';
    if (ans.size() < 2) cout << -1 << '\n';
    else cout << ans[ans.size()-1] + ans[ans.size()-2] << '\n';
}