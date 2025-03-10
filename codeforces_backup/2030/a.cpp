#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n], mx = 0, mi = INT_MAX;
    for (int i = 0; i < n; i++) cin >> a[i], mx = max(mx, a[i]), mi = min(mi, a[i]);
    cout << (mx - mi)*(n-1) << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}