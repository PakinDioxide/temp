/*
    author  : PakinDioxide
    created : 15/03/2025 18:32
    task    : D1_B
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector <tuple <ll, int, int>> E(m);
    for (auto &[w, u, v] : E) cin >> u >> v >> w;
    sort(E.begin(), E.end());
    vector <ll> e;
    int par[n+1];
    iota(par, par+n+1, 0);
    function <int(int)> fi = [&] (int x) {
        if (x != par[x]) return par[x] = fi(par[x]);
        return x;
    };
    for (auto &[w, u, v] : E) {
        if (fi(u) != fi(v)) {
            par[fi(u)] = par[fi(v)];
            e.push_back(w);
        }
    }
    ll ans = 0, mod = 1e9+7;
    for (int i = 0; i < max(0, (int) e.size() - k); i++) ans += e[i], ans %= mod;
    cout << ans << '\n';
}