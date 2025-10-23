/*
    author  : 
    created : 26/08/2025 21:47
    task    : 2134C
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n; ll a[n]; for (auto &e : a) cin >> e;
    ll c = 0;
    for (int i = 0; i < n; i+=2) {
        ll mn = a[i];
        if (i+1 < n) mn = min(mn, a[i+1]);
        if (i-1 >= 0) mn = min(mn, a[i-1]);
        c += max(0LL, a[i] - mn);
        a[i] = mn;
    }
    for (int i = 0; i < n-2; i+=2) {
        if (a[i] + a[i+2] <= a[i+1]) continue;
        int k = a[i] + a[i+2] - a[i+1];
        c += k;
        a[i+2] -= k; a[i+2] = max(a[i+2], 0LL);
    }
    cout << c << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}