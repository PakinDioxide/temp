/*
    author  : 
    created : 23/06/2025 21:37
    task    : 2112B
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    ll a[n]; for (auto &e : a) cin >> e;
    int mn = INT_MAX;
    for (int i = 0; i < n; i++) {
        ll p = LLONG_MAX, q = LLONG_MIN;
        for (int j = i+1; j < n; j++) {
            p = min(p, a[j]), q = max(q, a[j]);
            if (p - a[i] <= 1 && a[i] - q <= 1) { mn = min(mn, j-i-1); break;}
        }
    }
    reverse(a, a+n);
    for (int i = 0; i < n; i++) {
        ll p = LLONG_MAX, q = LLONG_MIN;
        for (int j = i+1; j < n; j++) {
            p = min(p, a[j]), q = max(q, a[j]);
            if (p - a[i] <= 1 && a[i] - q <= 1) { mn = min(mn, j-i-1); break;}
        }
    }
    if (mn == INT_MAX) cout << -1 << '\n';
    else cout << mn << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}