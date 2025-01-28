#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k = 10, ans = 0, x = 4;
    cin >> n;
    for (int i = 2; k < n; k*=10, i++) {
        x = 10*x+4;
        if (n < 5*k) ans += max(0, n - x);
        else ans += 5*k-x-1;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}