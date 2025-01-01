// PakinDioxide
#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector <int> adj[200005];
ll b[200005], dp[200005], par[200005], mm[200005], up[200005], ans[200005], cls[200005], mx[2], ii[2];

void dfs(int u, int p) {
    dp[u] = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        dp[u] = max(dp[u], dp[v]);
        par[v] = u;
    }
    dp[u] += b[u];
    // cout << u << ' ' << dp[u] << '\n';
}

void fimm(int u, int p) {
    int idx = 0;
    ll mx = 0;
    mm[u] = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (dp[v] > mx) mx = dp[v], idx = v;
    }
    if (idx != 0) fimm(idx, u);
}

void upp(int u, int p) {
    for (int v : adj[u]) {
        if (v == p) continue;
        up[v] = up[u] + b[v];
        cls[v] = cls[u];
        if (mm[u] && !mm[v]) up[v] = b[v], cls[v] = u;
        upp(v, u);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // cout << '\n';
    dfs(1, 0);
    fimm(1, 0);
    upp(1, 0);
    
    // for (int i = 1; i <= n; i++) 
}