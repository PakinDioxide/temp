/*
    author  : PakinDioxide
    created : 11/03/2025 21:56
    task    : 2074D
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    pair <ll, ll> a[n];
    for (int i = 0; i < n; i++) cin >> a[i].first;
    for (int i = 0; i < n; i++) cin >> a[i].second;
    sort(a, a+n);
    map <ll, ll> mp;
    for (auto [x, r] : a) {
        for (ll i = x-r; i <= x+r; i++) {
            ll y = sqrt(r*r - (x-i)*(x-i));
            mp[i] = max(mp[i], 2*y+1);
        }
    }
    ll ans = 0;
    for (auto e : mp) ans += e.second;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}