#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 5e5+5;

int n, m, s, p, a[mxN], vis[mxN], idx = 0, id[mxN], lo[mxN], onst[mxN], val[mxN], ok[mxN];
vector <int> adj[mxN];
stack <int> st;
set <int> adt[mxN];

void dfs(int u) {
    id[u] = lo[u] = ++idx, onst[u] = 1;
    st.emplace(u);
    for (auto v : adj[u]) {
        if (!id[v]) dfs(v);
        if (onst[v]) lo[u] = min(lo[u], lo[v]);
    }
    if (lo[u] == id[u]) {
        while (!st.empty()) {
            int x = st.top(); st.pop();
            onst[x] = 0;
            lo[x] = lo[u];
            if (x == u) break;
        }
    }
}

queue <int> q;

void topo(int u) {
    vis[u] = 1;
    for (auto v : adt[u]) if (!vis[v]) dfs(v);
    q.emplace(u);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 0, u, v; i < m; i++) cin >> u >> v, adj[u].emplace_back(v);
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> s >> p;
    dfs(s);
    for (int u = 1; u <= n; u++) for (auto v : adj[u]) if (lo[u] != lo[v]) adt[lo[v]].emplace(lo[u]);
    for (int i = 1; i <= n; i++) if (id[i] == lo[i]) topo(lo[i]);
    for (int i = 1; i <= n; i++) val[lo[i]] += a[i];
    for (int i = 0, x; i < p; i++) cin >> x, ok[lo[x]] = 1;
    while (q.front() != s) q.pop();
    int mx = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        int k = 0;
        for (auto v : adt[u]) k = max(k, val[v]);
        val[u] += k;
        if (ok[u]) mx = max(mx, val[u]);
    }
    cout << mx << '\n';
}