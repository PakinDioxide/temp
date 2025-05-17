/*
    author  : PakinDioxide
    created : 08/05/2025 11:49
    task    : codecube_043
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 305, mxK = 2005;

int n, m, k, s, t, upd = 1;
ll dp[mxN][mxK];
vector <tuple <int, ll, ll>> adj[mxN];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> k >> s >> t;
    for (int i = 1; i <= n; i++) for (int j = 0; j <= k; j++) dp[i][j] = LLONG_MIN;
    dp[s][0] = 0;
    for (int i = 0, u, v, c, w; i < m; i++) cin >> u >> v >> c >> w, adj[u].emplace_back(v, c, w), adj[v].emplace_back(u, c, w);
    for (int i = 0; i <= k; i++) for (int u = 1; u <= n; u++) if (dp[u][i] > LLONG_MIN) for (auto &[v, c, w] : adj[u]) if (i+w <= k && dp[v][i+w] < dp[u][i] + c) dp[v][i+w] = dp[u][i] + c;
    ll mx = LLONG_MIN;
    for (int i = 0; i <= k; i++) mx = max(mx, dp[t][i]);
    if (mx == LLONG_MIN) cout << "Impossible\n";
    else cout << mx << '\n';
}