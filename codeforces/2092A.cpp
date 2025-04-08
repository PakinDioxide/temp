/*
    author  : PakinDioxide
    created : 29/03/2025 21:34
    task    : 2092A
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    ll a[n], mn = LLONG_MAX, mx = 0;
    for (auto &e : a) cin >> e, mn = min(mn, e), mx = max(mx, e);
    cout << mx - mn << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}