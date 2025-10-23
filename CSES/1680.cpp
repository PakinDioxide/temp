/*
    author  : PakinDioxide
    created : 07/04/2025 03:17
    task    : 1678
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MX = 1e5+5;

int n, m, vis[MX], dp[MX], par[MX];
vector <int> adj[MX], topo;

void dfs(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    for (auto v : adj[u]) dfs(v);
    topo.emplace_back(u);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[v].emplace_back(u);
    }
    for (int i = 1; i <= n; i++) dp[i] = INT_MIN;
    dp[1] = 0;
    dfs(n);
    for (auto &u : topo) for (auto &v : adj[u]) if (dp[u] < dp[v] + 1) dp[u] = dp[v] + 1, par[u] = v;
    if (dp[n] < 0) {cout << "IMPOSSIBLE\n"; return 0;}
    int k = n;
    stack <int> st;
    while (k != 1) st.emplace(k), k = par[k];
    st.emplace(1);
    cout << st.size() << '\n';
    while (!st.empty()) cout << st.top() << ' ', st.pop();
    cout << '\n';
}