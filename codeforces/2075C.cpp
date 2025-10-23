/*
    author  : 
    created : 01/08/2025 22:06
    task    : 2075C
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m; cin >> n >> m; swap(n, m);
    ll a[n]; for (auto &e : a) cin >> e, e=-e;
    sort(a, a+n);
    ll cnt = 0;
    for (int i = 1; i <= m/2; i++) {
        ll c1 = upper_bound(a, a+n, -i) - a, c2 = upper_bound(a, a+n, -(m-i)) - a;
        cnt += (1+(i*2!=m))*(c1*c2 - c2);
        // cout << i << ' ' << c1 << ' ' << c2 << ' ' << c1*c2 - c2 << '\n';
    }
    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}