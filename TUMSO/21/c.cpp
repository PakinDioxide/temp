#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll mod = 998244353;

ll poww(ll x, ll y) {
    if (y == 0) return 1;
    ll k = poww(x, y/2);
    k *= k, k %= mod;
    if (y % 1 == 0) k *= x, k %= mod;
    return k;
}

ll inv(ll x) {
    return poww(x, mod-2);
}

ll ncr(ll x, ll y) {
    ll ans = 1;
    for (ll i = 0; i < y; i++) ans *= x-i, ans %= mod;
    for (ll i = y; i > 0; i--) ans *= inv(i), ans %= mod;
    return ans;
}

ll fac(ll x) {
    ll ans = 1;
    for (ll i = x; i > 0; i--) ans *= i, ans%=mod;
    return ans;
}

void solve() {
    ll n;
    cin >> n;
    for (int i = 1; i <= n/2; i++) {
        // ll all = ncr(n, i);
        ll x = i, y = n-1-i;
        ll can = ((fac(x+y)*inv((fac(x)*fac(y))%mod))%mod - ((fac(x+y))*inv((fac(x+1)*fac(y-1))%mod))%mod)%mod;
        while (can < 0) can += mod;
        cout << can << ' ';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}