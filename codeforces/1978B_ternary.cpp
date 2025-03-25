/*
    author  : PakinDioxide
    created : 14/03/2025 18:00
    task    : 1978B
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll n, a, b;
    cin >> n >> a >> b;
    ll l = 0, r = min(n, b), ans = 0;
    auto calc = [&] (ll x) {
        return b*x - x*(x-1)/2 + a*(n-x);
    };
    while (l <= r) {
        if (l == r) {ans = calc(l); break;}
        ll m1 = (l+r)/2, m2 = (l+r)/2+1;
        if (m1 == l && m2 == r) {ans = max(calc(m1), calc(m2)); break;}
        if (calc(m1) > calc(m2)) r = m2-1;
        else if (calc(m1) < calc(m2)) l = m1+1;
        else l = m1, r = m2;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}