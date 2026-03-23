#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    int a[n]; for (auto &e : a) cin >> e;
    int p[n], q[n], r[n], s[n];
    for (int i = 0; i < n; i++) p[i] = q[i] = r[i] = s[i] = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0) p[i] = q[i] = 1;
        else p[i] = min(p[i-1], (int) (a[i] <= a[i-1])), q[i] = min(q[i-1], (int) (a[i] >= a[i-1]));
    }
    for (int i = n-1; i >= 0; i--) {
        if (i == n-1) r[i] = s[i] = 1;
        else r[i] = min(r[i+1], (int) (a[i] <= a[i+1])), s[i] = min(s[i+1], (int) (a[i] >= a[i+1]));
    }
    /*
    for (int i = 0; i < n; i++) cout << p[i] << ' '; cout << '\n';
    for (int i = 0; i < n; i++) cout << q[i] << ' '; cout << '\n';
    for (int i = 0; i < n; i++) cout << r[i] << ' '; cout << '\n';
    for (int i = 0; i < n; i++) cout << s[i] << ' '; cout << '\n';
    */
    int ans = INT_MAX;
    if (q[n-1]) { cout << 0 << '\n'; return; }
    else if (p[n-1]) { cout << 1 << '\n'; return; }
    for (int i = 1; i < n; i++) {
        if (s[i] && p[i-1] && a[0] <= a[n-1]) ans = min(ans, n-i+1), ans = min(ans, (i+1));
        if (r[i] && q[i-1] && a[n-1] <= a[0]) ans = min(ans, n-i), ans = min(ans, i+2);
    }
    if (ans < INT_MAX) cout << ans << '\n';
    else cout << -1 << '\n';
}

/*  3 4 5 1 2 -> 2 1 5 4 3 */

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

