#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    int cnt = 0, l = 0, r = n-1;
    // for (int i : a) cout << i << ' ';
    // cout << '\n';
    while (l < r - 1) {
        if (a[l] + a[l+1] <= a[r]) {
            // cout << l << ' ' << r << '\n';
            if (a[l+2] - a[l] >= a[r] - a[r-1]) l++;
            else r--;
            cnt++;
        } else l++, r--;
    }
    cout << cnt << '\n';
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}