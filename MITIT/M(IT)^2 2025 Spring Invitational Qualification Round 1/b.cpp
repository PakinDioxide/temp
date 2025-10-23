/*
    author  : PakinDioxide
    created : 06/04/2025 22:02
    task    : b
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    ll a[n];
    for (auto &e : a) cin >> e;
    sort(a, a+n);
    vector <ll> d;
    d.emplace_back(0);
    for (int i = 0; i < n-1; i++) d.emplace_back(a[i+1] - a[i]);
    n = d.size()-1;
    ll p[n+1], s[n+2];
    p[0] = s[n+1] = LLONG_MAX;
    for (int i = 1; i <= n; i++) p[i] = min(d[i], p[i-1]);
    for (int i = n; i >= 1; i--) s[i] = min(d[i], s[i+1]);
    ll ans = LLONG_MAX;
    for (int i = 1; i <= n; i++) {
        ll mn = LLONG_MAX;
        if (i > 2) mn = min(mn, p[i-2]);
        if (i <= n-2) mn = min(mn, s[i+2]);
        if (mn == LLONG_MAX) continue;
        ans = min(ans, mn + d[i]);
    }
    // for (int i = 1; i <= n; i++) cout << d[i] << ' ';
    // cout << '\n';
    // for (int i = 1; i <= n; i++) cout << p[i] << ' ';
    // cout << '\n';
    // for (int i = 1; i <= n; i++) cout << s[i] << ' ';    
    // cout << '\n';
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}