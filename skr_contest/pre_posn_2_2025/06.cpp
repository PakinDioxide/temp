/*
    author  : PakinDioxide
    created : 17/03/2025 19:43
    task    : 06
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <tuple <ll, int, int>> e(m);
    for (auto &[w, u, v] : e) cin >> u >> v >> w;
    sort(e.begin(), e.end());
    int par[n+1];
    iota(par, par+n+1, 0);
    function <int(int)> fi = [&] (int x) {
        if (par[x] != x) return par[x] = fi(par[x]);
        return x;
    };
    vector <ll> ww;
    for (auto &[w, u, v] : e) {
        if (fi(u) != fi(v)) {
            ww.push_back(w);
            par[fi(u)] = fi(v);
        }
    }
    int q;
    cin >> q;
    while (q--) {
        ll k;
        cin >> k;
        cout << lower_bound(ww.begin(), ww.end(), k) - ww.begin() + 1 << '\n';
    }
}