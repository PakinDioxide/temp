#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll n, k;
    cin >> n >> k;
    ll fac[n];
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = 2*fac[i-1];
        if (fac[i-1] == -1 || fac[i] > k) fac[i] = -1;
    }
    ll l = 0, r = n-1, a[n];
    k--;
    for (int i = 1; i <= n; i++) {
        if (fac[n-i-1] > -1 && fac[n-i-1] <= k && i != n) {
            // cout << fac[n-i-1] << '\n';
            k -= fac[n-i-1];
            a[r] = i;
            r--;
        } else {
            a[l++] = i;
        }
    }
    if (k > 0) {cout << -1 << '\n'; return;}
    for (int i = 0; i < n; i++) cout << a[i] << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}