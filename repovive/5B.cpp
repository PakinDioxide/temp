#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    int a[n]; for (auto &e : a) cin >> e;
    if (k == 0) cout << a[0] << '\n';
    else if (k == n-1) cout << a[n-1] << '\n';
    else {
        int mx = 0;
        for (auto &e : a) mx = max(mx, e);
        cout << mx << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

