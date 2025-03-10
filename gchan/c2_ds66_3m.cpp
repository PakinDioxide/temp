#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n;
    cin >> n;
    ll cnt = 0;
    pair <ll, ll> a[n];
    for (auto &[l, r] : a) cin >> l >> r, cnt += r-l;
    ll l = 0, r = 2e7, med = max(1LL, cnt/2), ans = 0;
    while (l <= r) {
        ll x = l+(r-l)/2, cnt = 0;
        for (auto [L, R] : a) cnt += max(0LL, min(x, R-1) - L + 1);
        if (cnt >= med) {
            ans = x;
            r = x-1;
        } else l = x+1;
    }
    cout << ans << '\n';
}