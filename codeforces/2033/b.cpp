#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n][n], mx[2*n];
    for (int i = 0; i < 2*n; i++) mx[i] = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j], mx[i-j+n] = min(mx[i-j+n], a[i][j]);
    int sum = 0;
    for (int i = 0; i < 2*n; i++) sum -= mx[i];
    cout << sum << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}