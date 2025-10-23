/*
    author  : 
    created : 21/06/2025 22:07
    task    : 2120D
*/
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

ll inv(ll x) { return poww(x, mod-2); }

ll ncr(ll n, ll r) {
    if (r == 0) return 1;
    return ((((n-r+1 + mod) % mod)*inv(r))%mod * ncr(n, r-1)) % mod;
}

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    ll p1 = ((((n-1)*k)) % mod + 1) % mod;
    ll p2 = ((((k*ncr(p1, n))%mod)*(m-1)%mod)+1) % mod;
    cout << p1 << ' ' << p2 << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}