/*
    author  : PakinDioxide
    created : 
    task    : 
*/
#include <bits/stdc++.h>
#define ll long long
 
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m; cin >> n >> m;
    if (m == n-1) {
        vector <ll> ws(m);
        for (auto &e : ws) cin >> e, cin >> e, cin >> e;
        sort(ws.begin(), ws.end());
        ll p[m+1];
        p[0] = 0;
        for (int i = 1; i <= m; i++) p[i] = p[i-1] + ws[i-1];
        int q; cin >> q;
        ll xo = 0, mn = LLONG_MAX, idx = 0;
        for (int i = 1; i <= q; i++) {
            ll mst = 0, l; cin >> l;
            ll le = upper_bound(ws.begin(), ws.end(), l) - ws.begin();
            mst = (l*le - p[le]) + ((p[m] - p[le]) - (l * (m - le)));
            if (mst < mn) mn = mst, idx = i;
            xo ^= mst;
        }
        cout << idx << '\n' << xo << '\n';
        return 0;
    }
    vector <tuple <ll, int, int>> E(m);
    ll wm = LLONG_MAX, wx = LLONG_MIN;
    for (auto &[w, u, v] : E) cin >> u >> v >> w, wm = min(wm, w), wx = max(wx, w);
    // BRUTEFORCE :)
    int q; cin >> q;
    ll xo = 0, mn = LLONG_MAX, idx = 0;
    for (int i = 1; i <= q; i++) {
        ll l, mst = 0; cin >> l;
        if (wm == wx) {
            mst = abs(wm-l)*(n-1);
            if (mst < mn) mn = mst, idx = i;
            xo ^= mst;
            continue;
        }
        vector <tuple <ll, int, int>> E2 = E;
        for (auto &[w, u, v] : E2) w = abs(w-l);
        sort(E2.begin(), E2.end());
        vector <int> par(n+1);
        for (int i = 1; i <= n; i++) par[i] = i;
        function <int(int)> fi = [&] (int x) {
            if (x != par[x]) return par[x] = fi(par[x]);
            return x;
        };
        for (auto &[w, u, v] : E2) {
            if (fi(u) != fi(v)) mst += w, par[fi(u)] = fi(v);
        }
        if (mst < mn) mn = mst, idx = i;
        xo ^= mst;
    }
    cout << idx << '\n' << xo << '\n';
}
/*
    we precompute l for all road length
    when we answer l_i = x
    we will find the minimum between upper_bound - 1, upper_bound
    let k be the value of upper_bound-1 : k <= x
    before was |k-w| -> |x-w|
    if k < w -> (w-k -> w-x) diff = -x+k
    else if k > w -> (k-w -> x-w) diff = x-k
 */
