/*
    author  : PakinDioxide
    created : 24/03/2025 18:32
    task    : forbidden
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll n, k;
    cin >> n >> k;
    ll p[n+1], mx = 0;
    set <ll> v;
    v.insert(0);
    p[0] = 0;
    for (int i = 1; i <= n; i++) {
        ll e;
        cin >> e;
        e %= k;
        p[i] = (p[i-1] + e) % k;
        ll x = *prev(v.upper_bound(k-p[i]-1));
        mx = max(mx, p[i] + x);
        v.insert(k-p[i]);
    }
    cout << mx << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}