/*
    author  : PakinDioxide
    created : 09/04/2025 21:11
    task    : 1683_kosaraju
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;
int n, m, vis[mxN], g[mxN];
vector <int> adj[mxN], adjr[mxN];
stack <int> st;

void dfs1(int u) {
    vis[u] = 1;
    for (auto v : adj[u]) if (!vis[v]) dfs1(v);
    st.emplace(u);
}

void dfs2(int u, int k) {
    g[u] = k;
    for (auto v : adjr[u]) if (!g[v]) dfs2(v, k);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adjr[v].emplace_back(u);
    }
    for (int i = 1; i <= n; i++) if (!vis[i]) dfs1(i);
    int idx = 0;
    while (!st.empty()) {
        if (!g[st.top()]) dfs2(st.top(), ++idx);
        st.pop();
    }
    cout << idx << '\n';
    for (int i = 1; i <= n; i++) cout << g[i] << ' ';
    cout << '\n';
}