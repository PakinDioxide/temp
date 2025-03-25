/*
    author  : PakinDioxide
    created : 11/03/2025 21:39
    task    : 2074C
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll x;
    cin >> x;
    ll y = 1;
    while (y < x) {
        ll k = x ^ y;
        if (x + y > k && x + k > y && y + k > x) {cout << y << '\n'; return;}
        y = (y << 1) | 1;
    }
    cout << -1 << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}