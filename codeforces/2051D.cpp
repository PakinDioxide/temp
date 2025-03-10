#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll n, x, y;
    cin >> n >> x >> y;
    ll a[n], sum = 0, cnt = 0;
    for (int i = 0; i < n; i++) cin >> a[i], sum += a[i];
    sort(a, a+n);
    for (int i = 1; i < n; i++) {
        ll k = sum - a[i];
        if (k <= x) continue;
        int l = lower_bound(a, a+i, k-y) - a, r = upper_bound(a, a+i, k-x) - a - 1;
        // cout << k-y << ' ' << k-x << ' ' << l << ' ' << r << '\n';
        cnt += max(0, r-l+1);
    }
    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}