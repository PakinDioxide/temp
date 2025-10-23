#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    ll a[n]; for (auto &e : a) cin >> e;
    ll mx = -1;
    for (auto &e : a) mx = max(mx, e); cout << mx << '\n';
}

int main() {
    int t; cin >> t;
    while (t--) solve();
    void solve();
}