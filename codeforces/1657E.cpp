#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll mod = 998244353;

ll poww(ll x, ll y) {
    if (y == 0) return 1;
    ll k = poww(x, y/2);
    k *= k, k %= mod;
    if (y % 2 == 1) k *= x, k %= mod;
    return k;
}

ll inv(ll x) {
    return poww(x, mod-2);
}

ll ncr(ll x, ll y) {
    ll s = 1;
    for (int i = 1; i <= x; i++) s *= i, s %= mod;
    for (int i = 1; i <= y; i++) s *= inv(i), s %= mod;
    for (int i = 1; i <= x-y; i++) s *= inv(i), s %= mod;
    return s;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n, k; cin >> n >> k;
    ll ans = 0, t = n * (n-1) / 2 - (n-1);
    for (ll b = 1; b <= k; b++) {
        for (ll c = 1; c < n; c++) {
            ll cc = (n - 1) - c;
            ans += (((ncr((n - 1), c) * poww(b-1, cc)) % mod) * poww(k-b+1, t)) % mod;
            ans %= mod;
            // cout << b << ' ' << c << ' ' << ((ncr((n - 1), c) * poww(b-1, cc)) % mod) * poww(k-b+1, t) << '\n';
        }
    }
    cout << ans << '\n';
}

