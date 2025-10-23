/*
    author  : PakinDioxide
    created : 03/05/2025 11:05
    task    : 2101
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;

int n, m, q, par[mxN], rnk[mxN];
pair <int, int> P[mxN];

int fi(int x) { return x == par[x] ? x : par[x] = fi(par[x]); }

int vp(int x, int t) {
    if (P[x].second <= t && P[x].first != x) return vp(P[x].first, t);
    else return x;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> q;
    iota(par, par+n+1, 0);
    for (int i = 1; i <= n; i++) P[i] = {i, 0};
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        u = fi(u), v = fi(v);
        if (u == v) continue;
        if (rnk[u] < rnk[v]) swap(u, v);
        if (rnk[u] == rnk[v]) rnk[u]++;
        par[v] = u;
        P[v] = make_pair(u, i);
    }
    while (q--) {
        int u, v;
        cin >> u >> v;
        int l = 0, r = m, ans = -1;
        while (l <= r) {
            int x = l + (r-l)/2;
            if (vp(u, x) == vp(v, x)) ans = x, r = x-1;
            else l = x+1;
        }
        cout << ans << '\n';
    }
}