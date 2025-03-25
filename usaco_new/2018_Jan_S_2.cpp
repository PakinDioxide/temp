/*
    author  : PakinDioxide
    created : 17/03/2025 03:32
    task    : 2018_Jan_S_2
*/
#include <bits/stdc++.h>
#define ll long long
#define int long long

using namespace std;

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    ll a[n];
    for (auto &e : a) cin >> e;
    sort(a, a+n);
    pair <ll, ll> b[m];
    for (auto &[p, q] : b) cin >> q >> p;
    sort(b, b+m);
    ll c[k];
    for (auto &e : c) cin >> e;
    sort(c, c+k);
    int l = 0, r = n-1, ib = m-1, ic = k-1, sll[n];
    ll ans = 0;
    memset(sll, 0, sizeof(sll));
    while (l <= r) {
        // cout << l << ' ' << r << ' ' << ib << ' ' << ic << ' ' << ans << '\n';
        // cout << min(a[r], b[ib].second) * b[ib].first << ' ' << c[ic] << '\n';
        if (ic < 0 && ib < 0) break;
        if (ic < 0 || sll[r] || (ib >= 0 && min(a[r], b[ib].second) * b[ib].first >= c[ic])) {
            if (ib < 0) r--;
            ans += min(a[r], b[ib].second) * b[ib].first;
            sll[r] = 1;
            if (a[r] > b[ib].second) {
                a[r] -= b[ib].second;
                ib--;
            } else if (b[ib].second > a[r]) {
                b[ib].second -= a[r];
                r--;
            } else {
                ib--, r--;
            }
        } else {
            ans += c[ic];
            l++;
            ic--;
        }
    }
    // cout << l << ' ' << r << ' ' << ib << ' ' << ic << ' ' << ans << '\n';
    // cout << min(a[r], b[ib].second) * b[ib].first << ' ' << c[ic] << '\n';
    // if (sll[r]) {
    //     if (ib >= 0) ans += min(a[r], b[ib].second) * b[ib].first;
    //     sll[r] = 1;
    //     if (a[r] > b[ib].second) {
    //         a[r] -= b[ib].second;
    //         ib--;
    //     } else if (b[ib].second > a[r]) {
    //         b[ib].second -= a[r];
    //         r--;
    //     } else {
    //         ib--, r--;
    //     }
    // } else {
    //     if (ic < 0 || (ic >= 0 && ib >= 0 && min(a[r], b[ib].second) * b[ib].first >= c[ic])) {
    //         ans += min(a[r], b[ib].second) * b[ib].first;
    //         sll[r] = 1;
    //         if (a[r] > b[ib].second) {
    //             a[r] -= b[ib].second;
    //             ib--;
    //         } else if (b[ib].second > a[r]) {
    //             b[ib].second -= a[r];
    //             r--;
    //         } else {
    //             ib--, r--;
    //         }
    //     } else if (ic >= 0) {
    //         ans += c[ic];
    //     }
    // }
    cout << ans << '\n';
}