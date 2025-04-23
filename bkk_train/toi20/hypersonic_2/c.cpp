/*
    author  : PakinDioxide
    created : 11/04/2025 17:34
    task    : c
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;

ll n, m, x, q, a[mxN], b[mxN], co[mxN], par[mxN], Q[2*mxN], X[2*mxN], A[2*mxN];
pair <ll, ll> E[2*mxN];

int fi(int x) { return (x == par[x] ? x : (par[x] = fi(par[x]))); }

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> x;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 2; i <= n; i++) if (!(a[i] > a[1] && b[i] < b[1]) && !(a[1] > a[i] && b[1] < b[i])) co[i] = 1;
    iota(par, par+n+1, 0);
    for (int i = 1; i <= m; i++) cin >> E[i].first >> E[i].second;
    cin >> q;
    for (int i = 1; i <= q; i++) cin >> Q[i], X[Q[i]] = 1;
    for (int i = 1; i <= m; i++) if (!X[i]) { auto &[u, v] = E[i]; if (fi(u) != fi(v)) co[fi(u)] += co[fi(v)], par[fi(v)] = fi(u); }
    A[q+1] = co[fi(x)];
    for (int i = q; i >= 1; i--) { auto &[u, v] = E[Q[i]]; if (fi(u) != fi(v)) co[fi(u)] += co[fi(v)], par[fi(v)] = fi(u); A[i] = co[fi(x)]; }
    for (int i = 1; i <= q+1; i++) cout << A[i] << '\n';
}