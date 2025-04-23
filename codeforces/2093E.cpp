/*
    author  : PakinDioxide
    created : 08/04/2025 22:23
    task    : 2093E
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll n, k;
    cin >> n >> k;
    ll a[n];
    for (auto &e : a) cin >> e;
    ll l = 1, r = n+5, ans = 0;
    while (l <= r) {
        ll x = l + (r-l)/2, c = 0, cc = 0;
        map <ll, ll> vis;
        for (auto &e : a) {
            if (e >= x) continue;
            cc += (!vis[e]);
            vis[e] = 1;
            if (cc == x) c++, cc = 0, vis.clear();
        }
        // cout << x << ' ' << c << '\n';
        if (c >= k) ans = x, l = x+1;
        else r = x-1;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}