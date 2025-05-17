/*
    author  : PakinDioxide
    created : 03/05/2025 11:23
    task    : 2022_Dec_G_3
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;

int n, m, par[mxN], deg[mxN], mx = 0, V[mxN], C[mxN];

int fi(int x) { return x == par[x] ? x : par[x] = fi(par[x]); }

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    iota(par, par+n+1, 0);
    while (m--) {
        int u, v;
        cin >> u >> v;
        deg[u]++, deg[v]++;
        if (fi(u) != fi(v)) par[fi(v)] = fi(u);
    }
    for (int i = 1; i <= n; i++) V[i] = INT_MAX;
    for (int i = 1; i <= n; i++) V[fi(i)] = min(V[fi(i)], deg[i]), C[fi(i)]++;
    for (int i = 1; i <= n; i++) mx = max(mx, V[fi(i)]*C[fi(i)]), cout << i << ' ' << V[fi(i)] << ' ' << C[fi(i)] << '\n';
    cout << mx << '\n';
}