#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll mod = 1e9+7;

ll poww(ll x, ll y) {
    if (y == 0) return 1;
    ll k = poww(x, y/2);
    k *= k, k %= mod;
    if (y % 2 == 1) k *= x, k %= mod;
    return k;
}

void solve() {
    ll n, m, k; cin >> n >> m >> k;
    ll s = 0, c = 0, t = n*m-k;
    while (k--) {
        ll x, y, p; cin >> x >> y >> p;
        if ((x == 1 && y == m) || (x == n && y == 1) || (x == 1 && y == 1) || (x == n && y == m)) continue;
        if (x == n || x == 1 || y == m || y == 1) s ^= p, c--;
    }
    c += ((n-2) + (m-2)) * 2;
    t -= c;
    if (c == 0 && s == 1) { cout << 0 << '\n'; }
    else cout << (poww(2, c-1) * poww(2, t)) % mod << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

