/*
    author  : PakinDioxide
    created : 04/05/2025 10:56
    task    : codecube_080
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll M = 1e9+9, A = 9973;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    ll p[n], a[n];
    p[0] = 1, a[0] = s[0];
    for (int i = 1; i < n; i++) p[i] = (p[i-1] * A) % M, a[i] = ((a[i-1] * A) % M + s[i]) % M;
    for (int sz = 1; sz <= n; sz++) {
        if (n % sz != 0) continue;
        ll mn = LLONG_MAX, mx = LLONG_MIN;
        for (int l = 0; l < n; l += sz) {
            int r = l + sz-1;
            ll k = (a[r] - (l > 0 ? (a[l-1]*p[sz]) % M : 0) + M) % M;
            mn = min(mn, k);
            mx = max(mx, k);
        }
        if (mn == mx) {
            ll cnt = n/sz;
            ll c = 0;
            for (int i = 1; i <= cnt; i++) c += !(cnt % i);
            cout << c << '\n';
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t = 5;
    while (t--) solve();
}