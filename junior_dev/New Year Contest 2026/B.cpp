#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m; cin >> n >> m;
    vector <tuple <ll, int, int>> E(m);
    for (auto &[w, u, v] : E) cin >> u >> v >> w;
    sort(E.begin(), E.end());
    auto orz = [&] () {
        ll c = 0;
        int par[n+1]; iota(par, par+n+1, 0);
        function <int(int)> fi = [&] (int x) {
            if (x == par[x]) return x;
            return par[x] = fi(par[x]);
        };
        for (auto &[w, u, v] : E) if (fi(u) != fi(v)) {
            c += w;
            par[fi(u)] = fi(v);
        }
        return c;
    };
    ll k = orz();
    reverse(E.begin(), E.end());
    cout << orz() - k << '\n';
}

