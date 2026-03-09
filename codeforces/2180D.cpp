#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    ll a[n]; for (auto &e : a) cin >> e;
    ll mx[n];
    for (int i = 0; i < n; i++) {
        mx[i] = LLONG_MAX;
        if (i > 0) mx[i] = min(mx[i], a[i] - a[i-1]);
        if (i < n-1) mx[i] = min(mx[i], a[i+1] - a[i]);
    }
    ll L[n]; memset(L, 0, sizeof(L));
    L[0] = 0;
    for (int i = 1; i < n; i++) if (mx[i] + mx[i-1] > a[i] - a[i-1]) L[i] = L[i-1] + 1;
    ll ans = 0;
    for (int i = 1; i < n; i++) if (L[i] == 0) ans += L[i-1];
    // for (auto &e : L) cout << e << ' '; cout << '\n';
    ans += L[n-1];
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

