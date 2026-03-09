#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll a, b; cin >> a >> b;
    ll ans = 0, A = 0, B = 0;
    for (ll i = 0; A <= a && B <= b; i++) {
        if (i % 2 == 1) B += (1 << i);
        else A += (1 << i);
        ans = max(ans, i);
    }
    A = B = 0;
    for (ll i = 0; A <= a && B <= b; i++) {
        if (i % 2 == 1) A += (1 << i);
        else B += (1 << i);
        ans = max(ans, i);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

