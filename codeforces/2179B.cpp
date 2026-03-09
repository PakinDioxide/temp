#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    int a[n]; for (auto &e : a) cin >> e;
    ll s = 0, ans = LLONG_MAX;
    for (int i = 0; i < n-1; i++) s += abs(a[i+1] - a[i]);
    ans = min(ans, s - abs(a[1] - a[0]));
    ans = min(ans, s - abs(a[n-1] - a[n-2]));
    for (int i = 1; i < n-1; i++) {
        ans = min(ans, s - abs(a[i] - a[i-1]) - abs(a[i+1] - a[i]) + abs(a[i+1] - a[i-1]));
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

