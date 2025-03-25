/*
    author  : PakinDioxide
    created : 15/03/2025 18:01
    task    : D1_A
*/
#include <bits/stdc++.h>
#define ll long long
#define int long long

using namespace std;

vector <int> adj[200005];
ll a[200005], b[200005], c[200005];
ll dp[200005][2], ok[200005], vis[200005], okk[200005], viss[200005], dp2[200005][2];
int t;

void dfs1(int u) {
    if (viss[u]) return;
    viss[u] = 1;
    if (u == t) {okk[u] = 1; return;}
    for (int v : adj[u]) {
        dfs1(v);
        okk[u] += okk[v];
    }
}

void dfs(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    if (!okk[u]) return;
    if (b[u]) {
        if (okk[u] >= 2) dp[u][0] = dp[u][1] = c[u];
        else if (okk[u] == 1) dp[u][0] = c[u];
    }
    for (int v : adj[u]) {
        dfs(v);
        if (dp[v][0] == -1) continue;
        if (dp[v][0] + c[u] >= dp[u][0]) dp[u][1] = dp[u][0], dp[u][0] = dp[v][0] + c[u];
        else if (dp[v][0] + c[u] >= dp[u][1]) dp[u][1] = dp[v][0] + c[u];
        if (dp[v][1] == -1) continue;
        if (dp[v][1] + c[u] >= dp[u][0]) dp[u][1] = dp[u][0], dp[u][0] = dp[v][1] + c[u];
        else if (dp[v][1] + c[u] >= dp[u][1]) dp[u][1] = dp[v][1] + c[u];
    }
}

void dfs2(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    if (!okk[u]) return;
    if (a[u]) {
        dp2[u][0] = dp[u][0], dp2[u][1] = dp[u][1];
    }
    for (int v : adj[u]) {
        dfs2(v);
        // if (dp2[v][0] == -1) continue;
        if (dp2[v][0] >= dp2[u][0]) dp2[u][1] = dp2[u][0], dp2[u][0] = dp2[v][0];
        else if (dp2[v][0] >= dp2[u][1]) dp2[u][1] = dp2[v][0];
        // if (dp2[v][1] == -1) continue;
        if (dp2[v][1] >= dp2[u][0]) dp2[u][1] = dp2[u][0], dp2[u][0] = dp2[v][1];
        else if (dp2[v][1] >= dp2[u][1]) dp2[u][1] = dp2[v][1];
    }
}

void dfs3(int u) {
    if (u == 96526) cout << "YAY\n";
    if (vis[u]) return;
    vis[u] = 1;
    for (int v : adj[u]) {
        dfs3(v);
    }
}

int32_t main() {
    freopen("input-56.txt", "r", stdin);
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, cnta = 0, cntb = 0;
    cin >> n >> m >> t;
    for (int i = 0; i < m; i++) {int u, v; cin >> u >> v; adj[u].emplace_back(v);}
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) dfs1(i), dp[i][0] = dp[i][1] = -1;
    for (int i = 1; i <= n; i++) dfs(i);
    for (int i = 1; i <= n; i++) vis[i] = 0;
    for (int i = 1; i <= n; i++) dp2[i][0] = dp2[i][1] = -1;
    for (int i = 1; i <= n; i++) dfs2(i);
    memset(vis, 0, sizeof(vis));
    ll p = -1, q = -1;
    for (int i = 1; i <= n; i++) {
        if (okk[i] && a[i]) cout << i << '\n';
        if (dp[i][0] > -1 || dp[i][1] > -1) cout << dp[i][0] << ' ' << dp[i][1] << '\n';
        // if (!a[i]) continue;
        // cout << i << ' ' << dp2[i][0] << ' ' << dp2[i][1] << ' ' << okk[i] << '\n';
        // if (dp2[i][0] == -1) continue;
        if (dp2[i][0] >= p) q = p, p = dp2[i][0];
        else if (dp2[i][0] >= q) q = dp2[i][0];
        // if (dp2[i][1] == -1) continue;
        if (dp2[i][1] >= p) q = p, p = dp2[i][1];
        else if (dp2[i][1] >= q) q = dp2[i][1];
    }
    if (q == -1) cout << -1 << '\n';
    else cout << p+q << '\n';
    dfs3(67677);
    cout << dp[67677][0] << ' ' << dp[67677][1] << '\n';
}

/*
เงื่อนไข
    eat food -> copy -> coffee
graph no cycle

we just simply select food and coffee and compute the copy between the path

wow easy!!!
*/

