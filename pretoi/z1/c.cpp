#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector <pair <int, int>> adj[200005];
pair <int, int> up[200005];
int dep[200005], vis[200005];
map <pair <int, int>, int> dp;

void dfs(int u, int p) {
    vis[u] = 1;
    for (auto [v, w] : adj[u]) {
        if (v == p) continue;
        up[v] = {u, w};
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector <tuple <int, int, int>> E;
    for (int i = 0; i < m; i++) {int u, v, w; cin >> u >> v >> w; E.emplace_back(w, u, v);}
    sort(E.begin(), E.end());
    int par[n+5];
    for (int i = 1; i <= n; i++) par[i] = i;
    function <int(int)> fi = [&] (int x) {
        if (x != par[x]) return par[x] = fi(par[x]);
        return x;
    };
    for (int i = 0; i < m; i++) {
        auto [w, u, v] = E[i];
        if (fi(u) == fi(v)) continue;
        par[fi(u)] = fi(v);
        adj[v].emplace_back(u, w);
        adj[u].emplace_back(v, w);
    }
    for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i, 0);
    while (q--) {
        int u, v, p, uu, vv;
        cin >> u >> v >> p;
        if (dp[{u, v}] == 1) {cout << "TAIP\n"; continue;}
        else if (dp[{u, v}] == 2) {cout << "NE\n"; continue;}
        if (fi(u) != fi(v)) {dp[{u, v}] = 2; cout << "NE\n"; continue;}
        uu = u, vv = v;
        int mx = INT_MIN;
        if (dep[v] > dep[u]) swap(u, v);
        while (dep[u] > dep[v]) {if (mx > p) break; mx = max(mx, up[u].second), u = up[u].first;}
        while (u != v) {if (mx > p) break; mx = max({mx, up[u].second, up[v].second}), u = up[u].first, v = up[v].first;}
        if (mx > p) dp[{uu, vv}] = 2, cout << "NE\n";
        else dp[{uu, vv}] = 1, cout << "TAIP\n";
    }
}