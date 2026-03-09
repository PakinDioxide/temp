#include <bits/stdc++.h>
#define ll long long
#define int ll

using namespace std;

void solve() {
    int n; cin >> n;
    int c[n]; for (auto &e : c) cin >> e;
    int a[n]; for (auto &e : a) cin >> e;
    int b[n]; for (auto &e : b) cin >> e;
    int mx = 0, curr = 0;
    for (int i = 1; i < n; i++) {
        if (i == 1) {
            if (a[i] != b[i]) curr = abs(b[i] - a[i]);
        } else {
            if (a[i] == b[i]) curr = 0;
            else curr += c[i-1] - 1 - abs(b[i] - a[i]);
        }
        curr = max(curr, abs(b[i] - a[i]));
        curr += 2;
        mx = max(mx, curr + c[i] - 1);
    }
    cout << mx << '\n';
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

