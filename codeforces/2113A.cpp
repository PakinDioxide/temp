/*
    author  : 
    created : 15/06/2025 16:04
    task    : 2113A
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll a, x, b, y, k; cin >> k >> a >> b >> x >> y;
    if (x > y) swap(a, b), swap(x, y);
    ll cnt = 0;
    if (k >= a) cnt += ((k-a)/x+1), k -= x*((k-a)/x+1);
    if (k >= b) cnt += ((k-b)/y+1);
    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}