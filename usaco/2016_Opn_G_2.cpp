/*
    author  : PakinDioxide
    created : 03/05/2025 09:10
    task    : 2016_Opn_G_2
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;

int n, m, par[mxN], ok[mxN], Q[mxN], ans[mxN], c = 0;
vector <int> adj[mxN];

int fi(int x) { return x == par[x] ? x : par[x] = fi(par[x]); }

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0, u, v; i < m; i++) cin >> u >> v, adj[u].emplace_back(v), adj[v].emplace_back(u);
    for (int i = 0; i < n; i++) cin >> Q[i], ok[Q[i]] = 1;
    iota(par, par+n+1, 0);
    for (int i = n-1; i >= 0; i--) {
        c++;
        ok[Q[i]] = 0;
        for (auto &v : adj[Q[i]]) if (!ok[v] && fi(Q[i]) != fi(v)) c--, par[fi(v)] = fi(Q[i]);
        ans[i] = c;
    }
    for (int i = 0; i < n; i++) cout << (ans[i] == 1 ? "YES\n" : "NO\n");
}