#include <bits/stdc++.h>
#define ll long long
#define int long long

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for (auto &e : a) cin >> e;
    for (auto &e : b) cin >> e;
    sort(b, b+m);
    int ok = 1;
    a[0] = b[0] - a[0];
    for (int i = 1; i < n; i++) {
        int B = a[i-1] + a[i];
        int idx = lower_bound(b, b+m, B) - b;
        if (idx == m && a[i] < a[i-1]) {ok = 0; break;}
        if (a[i-1] > a[i] && idx < m) a[i] = b[idx] - a[i];
        else if (idx < m) a[i] = min(a[i], b[idx] - a[i]);
        // cout << a[i] << ' ';
    }
    if (ok) cout << "YES\n";
    else cout << "NO\n";
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}