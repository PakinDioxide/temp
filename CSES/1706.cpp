#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m; cin >> n >> m;
    vector <pair <int, int>> E(m);
    int par[n+1], co[n+1]; iota(par, par+n+1, 0); for (auto &e : co) e = 1;
    function <int(int)> fi = [&] (int x) {
        if (x == par[x]) return x;
        else return par[x] = fi(par[x]);
    };
    for (auto &[u, v] : E) {
        cin >> u >> v;
        if (fi(u) != fi(v)) co[fi(u)] += co[fi(v)], par[fi(v)] = fi(u);
    }
    bitset <100005> ans; ans[0] = 1;
    int vis[n+1]; memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) if (!vis[fi(i)]) vis[fi(i)] = 1, ans |= ans << co[fi(i)];
    for (int i = 1; i <= n; i++) cout << ans[i]; cout << '\n';
}