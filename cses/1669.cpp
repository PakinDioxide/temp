#include <bits/stdc++.h>

using namespace std;

int n, m;
vector <int> adj[200005];
int lo[200005], vis[200005], id[200005], idx = 1, vv[200005];
stack <int> o;
vector <int> a, aa;

void dfs(int u, int p) {
    if (vis[u]) return;
    lo[u] = id[u] = idx++;
    vis[u] = 1;
    o.push(u);
    for (int v : adj[u]) {
        if (v == p) continue;
        if (!vis[v]) dfs(v, u);
        lo[u] = min(lo[u], lo[v]);
    }
    if (id[u] == lo[u]) {
        vector <int> anss = {u};
        while (1) {
            if (lo[o.top()] == lo[u]) anss.push_back(o.top());
            if (o.top() == u) {o.pop(); break;}
            o.pop();
        }
        if (anss.size() == 2) return;
        a.push_back(u);
    }
}

void ans(int u, int p) {
    aa.push_back(u);
    if (vv[u]) {
        vector <int> aa2 = {aa.back()};
        aa.pop_back();
        while (aa.back() != aa2[0]) aa2.push_back(aa.back()), aa.pop_back();
        cout << aa2.size()+1 << '\n';
        for (int i : aa2) cout << i << ' ';
        cout << aa2[0];
        exit(0);
    }
    vv[u] = 1;
    for (int v : adj[u]) {
        if (v == p || lo[u] != lo[v]) continue;
        ans(v, u);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) dfs(i, -1);
    for (int i : a) ans(i, i);
    cout << "IMPOSSIBLE\n";
}