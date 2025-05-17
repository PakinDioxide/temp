/*
    author  : PakinDioxide
    created : 01/05/2025 21:39
    task    : 2108B
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll n, x;
    cin >> n >> x;
    ll ans = 0;
    for (int i = 0; i < 31; i++) {
        cout << n << ' ' << i << '\n';
        if (n == 0) { ans += (x & (1 << i)); continue; }
        if (x & (1 << i)) {
            if (n % 2 == 1) ans += n * (1 << i), n = 0;
            else ans += (n-1) * (1 << i), n = 0;
        } else {
            if (n % 2 == 0) ans += n * (1 << i), n = 0;
            else ans += (n-1) * (1 << i), n = 0;
        }
    }
    if (n) cout << -1 << '\n';
    else cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}