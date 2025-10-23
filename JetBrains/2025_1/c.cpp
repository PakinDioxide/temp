#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll __lcm(ll x, ll y) { return x * y / __gcd(x, y); }

void solve() {
    ll n; cin >> n;
    ll c = n;
    for (int i = 1; i < (1 << 9); i++) {
        ll lcm = -1, cnt = 0;
        for (int j = 0; j < 9; j++) if (i & (1 << j)) cnt++, lcm = (lcm == -1 ? j+2 : __lcm(lcm, j+2));
        if (cnt % 2 == 0) c += n/lcm;
        else c -= n/lcm;
    }
    cout << c << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    // int t; cin >> t;
    int t = 1;
    while (t--) solve();
}