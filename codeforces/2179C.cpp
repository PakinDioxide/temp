#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    ll a[n]; for (auto &e : a) cin >> e;
    sort(a, a+n);
    ll g = a[1] - a[0];
    for (int i = 2; i < n; i++) g = min(g, a[i] - a[0]);
    cout << max(g, a[0]) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

