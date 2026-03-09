#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    ll a[n+1]; for (int i = 1; i <= n; i++) cin >> a[i];
    ll p[n+2]; p[n+1] = 0;
    for (int i = n; i > 0; i--) p[i] = p[i+1] + a[i];
    ll s = 0, ans = LLONG_MIN;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, s - p[i+1]);
        s += (i > 1 ? abs(a[i]) : a[i]);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

