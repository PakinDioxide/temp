#include <bits/stdc++.h>

using namespace std;

int par[200005], co[200005], n, m, cnt, mx = 1;

int fi(int u) {
    if (par[u] != u) return par[u] = fi(par[u]);
    else return par[u];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    cnt = n;
    for (int i = 1; i <= n; i++) par[i] = i, co[i] = 1;
    while (m--) {
        int u, v;
        cin >> u >> v;
        if (fi(u) != fi(v)) cnt--, co[fi(u)] += co[fi(v)], par[fi(v)] = fi(u);
        mx = max(mx, co[fi(u)]);
        cout << cnt << ' ' << mx << '\n';
    }
}