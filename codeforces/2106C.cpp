/*
    author  : PakinDioxide
    created : 24/04/2025 21:41
    task    : 2106C
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    ll a[n], b[n];
    ll cmp = -1, mx = 0, mn = INT_MAX;
    for (auto &e : a) cin >> e, mx = max(mx, e), mn = min(mn, k+e);
    for (auto &e : b) cin >> e;
    for (int i = 0; i < n; i++) if (b[i] > -1) {
        if (cmp == -1) cmp = a[i] + b[i];
        else if (cmp != a[i] + b[i]) {cout << 0 << '\n'; return;}
    }
    if (cmp != -1) {
        int ok = 1;
        for (auto &e : a) if (cmp - e > k || cmp - e < 0) ok = 0;
        cout << ok << '\n';
    } else {

        cout << mn - mx + 1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}