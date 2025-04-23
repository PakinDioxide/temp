/*
    author  : PakinDioxide
    created : 19/04/2025 19:10
    task    : c2_knb64_rattaban
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    int par[n+1];
    iota(par, par+n+1, 0);
    tuple <int, int, int> E[m];
    map <pair <int, int>, int> mp;
    for (auto &[w, u, v] : E) {
        cin >> u >> v >> w;
        if (u > v) swap(u, v);
        mp[{u, v}] = min(mp[{u, v}], w);
    }
    sort(E, E+m);
    function <int(int)> fi = [&] (int x) {
        if (x != par[x]) return par[x] = fi(par[x]);
        return x;
    };
    vector <int> k;
    int ans1 = 0, ans2 = INT_MAX;
    for (int i = 0; i < m; i++) {
        auto &[w, u, v] = E[i];
        if (fi(u) != fi(v)) ans1 += w, par[fi(u)] = fi(v), k.emplace_back(i);
    }
    for (auto &e : k) {
        int t = 0, c = 0;
        iota(par, par+n+1, 0);
        for (int i = 0; i < m; i++) if (i != e) {
            auto &[w, u, v] = E[i];
            if (fi(u) != fi(v)) t += w, par[fi(u)] = fi(v), c++;
        }
        if (c == n-1) ans2 = min(ans2, t);
    }
    cout << ans1 << ' ' << ans2 << '\n';
}