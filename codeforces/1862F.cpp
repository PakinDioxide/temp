#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll w, f; cin >> w >> f;
    int n; cin >> n;
    ll a[n], s = 0; for (auto &e : a) cin >> e, s += e;
    ll L = 0, R = 2e6, ans = 0;
    sort(a, a+n);
    while (L <= R) {
        ll e = L + (R-L)/2;
        ll x = w*e, y = f*e;
        ll mx = 0;
        bitset <(int) 1e6+5> bt;
        int ok = 0;
        if (x+y < s) goto bruh;
        else if (x >= s || y >= s) { ok = 1; goto bruh; }
        bt[0] = 1;
        for (auto &k : a) bt |= (bt << k);
        for (int i = 0; i <= x; i++) if (bt[i]) mx = i;
        if (y >= s - mx) ok = 1;

        bruh:
        if (ok) ans = e, R = e-1;
        else L = e+1;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

