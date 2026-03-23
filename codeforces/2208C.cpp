#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    long double c[n], p[n];
    for (int i = 0; i < n; i++) cin >> c[i] >> p[i];
    long double mx = 0;
    for (int i = n-1; i >= 0; i--) {
        mx = max(mx, mx * (1 - p[i] / 100) + c[i]);
    }
    cout << fixed << setprecision(9) << mx << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

