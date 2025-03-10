#include <bits/stdc++.h>
#define ll long long
#define int long long

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    int a[n], b[m], k = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    k = a[0];
    sort(a, a+n);
    // sort(b, b+m);
    int can[m], idx = 0, sum = 0;
    while (idx < n && a[idx] <= k) idx++;
    for (int i = 0; i < m; i++) {
        if (b[i] <= k) can[i] = 1;
        else can[i] = n - (upper_bound(a+idx, a+n, b[i]-1) - a) + 1;
    }
    sort(can, can+m);
    // idx++;
    for (int k = 1; k <= m; k++) {
        int cnt = 0;
        for (int i = k-1; i < m; i+=k) cnt += can[i];
        cout << cnt << ' ';
    }
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}