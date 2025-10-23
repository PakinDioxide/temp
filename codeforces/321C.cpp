/*
    author  : 
    created : 20/08/2025 22:38
    task    : 321C
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;

int n, sz[mxN], vis[mxN];
char ans[mxN];
vector <int> adj[mxN];

int fsz(int u, int p) {
    sz[u] = 1;
    for (auto v : adj[u]) if (v != p && !vis[v]) sz[u] += fsz(v, u);
    return sz[u];
}

int fct(int u, int p, int tsz) {
    for (auto v : adj[u]) if (v != p && !vis[v] && 2 * sz[v] > tsz) return fct(v, u, tsz);
    return u;
}

void ctd(int u, char p) {
    int C = fct(u, u, fsz(u, u));
    ans[C] = p;
    vis[C] = 1;
    for (auto v : adj[C]) if (!vis[v]) ctd(v, p+1);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1, u, v; i < n; i++) cin >> u >> v, adj[u].emplace_back(v), adj[v].emplace_back(u);
    ctd(1, 'A');
    for (int i = 1; i <= n; i++) cout << ans[i] << ' '; cout << '\n';
}