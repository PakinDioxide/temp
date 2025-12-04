#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll c = 1, cc = 0, mx = 1e18;
    for (int i = 2; cc < 8; i++) {
        int ok = 1;
        for (int j = 2; j < i-1; j++) if (i % j == 0) ok = 0;
        if (!ok) continue;
        ll x = i; cc++;
        cout << i << ' ';
        ll ccc = 0;
        while (x <= mx) x*=i, ccc++;
        c *= ccc;
    }
    cout << '\n' << c << '\n';
    // int n; cin >> n;
    // ll p[n]; for (auto &e : p) cin >> e;
    // ll k; cin >> k;
    // ll L = 1, R = 1e18, ans = 1;
    // while (L <= R) {
    //     ll x = L + (R-L)/2;
    //     ll c = 0;
    //     for (int i = 0; i < (1 << n); i++) {
    //         ll y = 1, cc = 0;
    //         for (int j = 0; j < n; j++) if (i & (1 << j)) y *= p[j], cc++;
    //         if (cc % 2 == 0) c += x/y;
    //         else c -= x/y;
    //     }
    //     if (c >= k) ans = x, R = x-1;
    //     else L = x+1;
    // }
    // cout << ans << '\n';
}