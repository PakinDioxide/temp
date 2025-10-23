/*
    author  : 
    created : 05/07/2025 21:37
    task    : 2119B
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll n, x1, y1, x2, y2; cin >> n >> x1 >> y1 >> x2 >> y2;
    ll a[n];
    for (auto &e : a) cin >> e;
    // sort(a, a+n);
    // reverse(a, a+n);
    ll l = a[0], r = a[0];
    for (int i = 1; i < n; i++) l = (l <= a[i] && a[i] <= r ? 0 : min(abs(l-a[i]), abs(r-a[i]))), r += a[i];
    ll dis = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    if (l*l <= dis && r*r >= dis) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}