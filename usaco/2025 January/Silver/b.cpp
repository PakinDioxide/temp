#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll n, m;
    cin >> n >> m;
    ll a[n+1];
    for (int i = 1; i <= n; i++) cin >> a[i], a[i] %= m;
    sort(a+1, a+1+n);
    // for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    // cout << '\n';
    ll p[n+2], ans = LLONG_MAX;
    p[0] = 0;
    for (int i = 1; i <= n; i++) p[i] = p[i-1] + a[i];
    p[n+1] = p[n];
    int l = 0, r = 1+1;
    for (int i = 1; i <= n; i++) {
        ll sum = 0, x = a[i];
        r = min((int) n, max(r, i+1));
        while (r+1 <= n && a[r+1]-x <= m - a[r+1] + x) r++;
        while (l+1 < i && a[l+1]-x+m <= x - a[l+1]) l++;
        sum = p[l] + (-x+m)*l;
        sum += -(p[i-1] - p[l]) + (i-1-l)*x;
        sum += (p[r] - p[i]) - x*(r-i);
        sum += -(p[n] - p[r]) + (m+x)*(max(0LL, n-r));
        ans = min(ans, sum);
        // cout << a[i] << ' ' << i << ' ' << sum << '\n';
        // cout << 1 << ' ' << l << ' ' << i << ' ' << r << ' ' << n << '\n';
        // cout << "K " << p[l] + (-x+m)*l << ' ' << -(p[i-1] - p[l]) + (i-1-l)*x << ' ' << (p[r] - p[i]) - x*(r-i) << ' ' << -(p[n] - p[r]) + (m+x)*(max(0LL, n-r)) << '\n';
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}

// less than x : new = m - (e-x+m) = x - e;
//                   = e-x+m
// more than x : new = m - (e-x) = m - e + x
//                   = e-x