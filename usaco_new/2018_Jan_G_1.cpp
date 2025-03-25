/*
    author  : PakinDioxide
    created : 25/03/2025 03:29
    task    : 2018_Jan_G_1
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    int n, q, ii = 0;
    cin >> n >> q;
    tuple <int, int, int> E[n-1], Q[q];
    for (auto &[w, u, v] : E) cin >> u >> v >> w;
    for (auto &[k, u, id] : Q) cin >> k >> u, id = ii++;
    sort(E, E+n-1);
    reverse(E, E+n-1);
    sort(Q, Q+q);
    int par[n+1], co[n+1];
    for (int i = 1; i <= n; i++) par[i] = i, co[i] = 1;
    int idx = q-1, ans[q];
    function <int(int)> fi = [&] (int x) {
        if (par[x] != x) return par[x] = fi(par[x]);
        return x;
    };
    for (auto &[w, u, v] : E) {
        while (idx >= 0 && get<0>(Q[idx]) > w) {auto [k, u, id] = Q[idx]; ans[id] = co[fi(u)]-1; idx--;}
        if (fi(u) == fi(v)) continue;
        co[fi(v)] += co[fi(u)];
        par[fi(u)] = fi(v);
    }
    while (idx >= 0) {auto [k, u, id] = Q[idx]; ans[id] = co[fi(u)]-1; idx--;}
    for (auto &e : ans) cout << e << '\n';
}