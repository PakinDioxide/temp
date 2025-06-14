/*
    author  : PakinDioxide
    created : 17/04/2025 00:19
    task    : two_edge_connected_components
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;

int n, m, lo[mxN], id[mxN], onst[mxN], idx = 0;
vector <pair <int, int>> adj[mxN];
stack <int> st;
map <int, vector <int>> mp;

void dfs(int u, int p) {
    lo[u] = id[u] = ++idx;
    st.emplace(u);
    onst[u] = 1;
    for (auto [v, w] : adj[u]) {
        if (w == p) continue;
        if (!id[v]) dfs(v, w);
        lo[u] = min(lo[u], lo[v]);
    }
    if (lo[u] == id[u]) {
        while (1) {
            int e = st.top();
            st.pop();
            if (onst[e]) lo[e] = lo[u], onst[e] = 0;
            if (e == u) break;
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
    }
    for (int i = 0; i < n; i++) if (!id[i]) dfs(i, i);
    for (int i = 0; i < n; i++) mp[lo[i]].emplace_back(i);
    cout << mp.size() << '\n';
    for (auto &[x, y] : mp) {
        cout << y.size() << ' ';
        for (auto &e : y) cout << e << ' ';
        cout << '\n';
    }
}