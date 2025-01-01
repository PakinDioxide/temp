#include <bits/stdc++.h>

using namespace std;

int n, a[25], ans = INT_MAX;

void brf(int i, int c, int gcd) {
    if (i == n || gcd == 1) {
        if (gcd == 1) ans = min(ans, c);
        return;
    }
    brf(i+1, c, gcd == -1 ? a[i] : __gcd(gcd, a[i]));
    brf(i+1, c + n-i, gcd == - 1 ? __gcd(a[i], i+1) : __gcd(gcd, __gcd(a[i], i+1)));
}

void solve() {
    ans = INT_MAX;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    brf(0, 0, -1);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}