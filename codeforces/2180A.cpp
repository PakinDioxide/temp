#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll l, a, b; cin >> l >> a >> b;
    ll mx = 0;
    for (int i = 0; i <= l; i++) mx = max(mx, (a + i*b) % l);
    cout << mx << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

