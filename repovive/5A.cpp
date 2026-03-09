#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll l, r, x; cin >> l >> r >> x;
    cout << max(0ll, min(x-l+1, r-x+1)) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

