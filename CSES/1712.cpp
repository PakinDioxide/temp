/*
    author  : PakinDioxide
    created : 05/04/2025 21:46
    task    : 1712
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll poww(ll x, ll y, ll mod) {
    if (y == 0) return 1;
    ll k = poww(x, y/2, mod); k *= k, k %= mod;
    if (y & 1ll) k *= x, k %= mod;
    return k;
}

void solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    cout << poww(a, poww(b, c, 1e9+7 - 1), 1e9+7) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}

/*
a^b^c = a^b^c/2 * ... * a^b^c/2 = (a^b^c/2)^(b^c/2)
if c % 2 == 1, k ^= b
*/