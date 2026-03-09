#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll mod = 998244353;

ll fac(ll x) {
    ll s = 1;
    while (x) s *= x, s %= mod, x--;
    return s;
}

ll poww(ll x, ll y) {
    if (y == 0) return 1;
    ll k = poww(x, y/2);
    k *= k, k %= mod;
    if (y % 2 == 1) k *= x, k %= mod;
    return k;
}

ll inv(ll x) { return poww(x, mod-2); }

ll ncr(ll x, ll y) {
    ll s = fac(x);
    s *= inv(fac(y)), s %= mod;
    s *= inv(fac(x-y)), s %= mod;
    return s;
}

void solve() {
    int n; cin >> n;
    ll k; cin >> k;
    ll a[n]; for (auto &e : a) cin >> e;
    // must get from own box first,
    ll mn = 0;
    for (auto &e : a) mn = min(mn, e);
    for (auto &e : a) e -= mn;
    sort(a, a+n);
    reverse(a, a+n);
    ll c = 0;
    for (auto &e : a) if (e < a[0]) c += (a[0] - 1) - e;
    if (c > k) { cout << 0 << '\n'; return; }
    k -= c;
    ll cc = 0;
    for (auto &e : a) if (e == a[0]) cc++;
    ll c2 = cc;
    cc += k;
    if (cc >= n) { cout << fac(n) << '\n'; return; }
    else cout << (((fac(cc) * ncr(n-c2, k)) % mod) * fac(n-cc)) % mod << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

