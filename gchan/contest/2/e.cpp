#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll par[100005];

ll fi(ll x) {
    if (par[x] != x) return par[x] = fi(par[x]);
    return x;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n, m, k, cnt = 0, cst = 0;
    cin >> n >> m >> k;
    for (ll i = 0; i < n; i++) par[i] = i;
    vector <tuple <ll, ll, ll>> e(m);
    for (auto &[w, u, v] : e) cin >> u >> v >> w, w*=-1;
    sort(e.begin(), e.end());
    ll mn = LLONG_MAX, ok = 0, mmx = LLONG_MAX, cccnt = 0;
    for (auto [w, u, v] : e) {
        w*=-1;
        if (fi(u) == fi(v)) {
            if (w < k) mmx = min(mmx, k-w), cccnt++;
            else if (w == k) ok = 1;
            else mn = min(mn, w-k);
            continue;
        }
        par[fi(u)] = fi(v);
        cnt++;
        if (w <= k) cst += k-w, ok = 1;
        else mn = min(mn, w-k);
    }
    if (cnt == n-1 && !ok) {
        if (mmx < mn) cst += cccnt + min(k, -1 + mmx);
        else cst += cccnt + min(k, mn);
    } else cst += cccnt;
    cout << cst + (n-1-cnt)*k;
}