/*
    author  : 
    created : 23/08/2025 22:55
    task    : P1364
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 105;

ll n, mn = LLONG_MAX, a[mxN], f[mxN], sz[mxN];
vector <int> adj[mxN];

void dfs(int u) {
    sz[u] = a[u];
    for (auto v : adj[u]) dfs(v), sz[u] += sz[v], f[u] += f[v] + sz[v];
}

void rt(int u, ll val) {
    mn = min(mn, val + f[u]);
    for (auto v : adj[u]) rt(v, val + (f[u] - (f[v] + sz[v]) + (sz[1] - sz[v])));
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int l, r; cin >> a[i] >> l >> r;
        if (l) adj[i].emplace_back(l);
        if (r) adj[i].emplace_back(r);
    }
    dfs(1);
    rt(1, 0);
    cout << mn << '\n';
}