#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;

int n, k, sz[mxN], d[mxN];
vector <int> adj[mxN];
bool vis[mxN];

int fsz(int u, int p) {
    sz[u] = 1;
    for (auto v : adj[u]) if (v != p && !vis[v]) sz[u] += fsz(v, u);
    return sz[u];
}

int ct(int u, int p, int tsz) {
    for (auto v : adj[u]) if (v != p && !vis[v] && sz[v] * 2 > tsz) return ct(v, u, tsz);
    return u;
}

ll ans = 0;
vector <int> used;

void get_cnt(int u, int p, int f, int dep) {
    if (dep > k) return;
    if (f) d[dep]++, used.emplace_back(dep);
    else ans += d[k-dep];
    for (auto v : adj[u]) if (v != p && !vis[v]) get_cnt(v, u, f, dep+1);
}

void ctd(int u) {
    int C = ct(u, u, fsz(u, u));
    vis[C] = 1;
    for (auto v : adj[C]) if (!vis[v]) {
        get_cnt(v, C, 0, 1);
        get_cnt(v, C, 1, 1);
    }
    while (!used.empty()) d[used.back()] = 0, used.pop_back();
    for (auto v : adj[C]) if (!vis[v]) ctd(v);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    d[0] = 1;
    for (int i = 1, u, v; i < n; i++) cin >> u >> v, adj[u].emplace_back(v), adj[v].emplace_back(u);
    ctd(1);
    cout << ans << '\n';
}