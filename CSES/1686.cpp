/*
    author  : PakinDioxide
    created : 09/04/2025 21:26
    task    : 1686
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;
int n, m, vis[mxN], g[mxN], deg[mxN];
ll a[mxN], dp[mxN], sg[mxN];
vector <int> adj[mxN], adjr[mxN], adjs[mxN], topo;
pair <int, int> E[2*mxN];
stack <int> st;

void dfs1(int u) {
    vis[u] = 1;
    for (auto v : adj[u]) if (!vis[v]) dfs1(v);
    st.emplace(u);
}

void dfs2(int u, int k) {
    g[u] = k;
    sg[g[u]] += a[u];
    for (auto v : adjr[u]) if (!g[v]) dfs2(v, k);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adjr[v].emplace_back(u);
        E[i] = make_pair(u, v);
    }
    for (int i = 1; i <= n; i++) if (!vis[i]) dfs1(i);
    int idx = 0;
    while (!st.empty()) {
        if (!g[st.top()]) dfs2(st.top(), ++idx);
        st.pop();
    }
    for (int i = 0; i < m; i++) {auto &[u, v] = E[i]; if (g[u] != g[v]) adjs[g[u]].emplace_back(g[v]), deg[g[v]]++;}
    queue <int> q;
    for (int i = 1; i <= idx; i++) if (deg[i] == 0) q.emplace(i);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo.emplace_back(u);
        for (auto v : adjs[u]) if (--deg[v] == 0) q.emplace(v);
    }
    ll ans = 0;
    for (auto &u : topo) {
        dp[u] += sg[u];
        for (auto v : adjs[u]) dp[v] = max(dp[v], dp[u]);
        ans = max(ans, dp[u]);
    }
    cout << ans << '\n';
}