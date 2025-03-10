#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, ok = 1;
    cin >> n;
    ll a[n];
    for (auto &e : a) cin >> e;
    for (int i = 0; i < n; i++) {
        if (2*i >= a[i] || (n-i-1)*2 >= a[i]) ok = 0;
    }
    cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}