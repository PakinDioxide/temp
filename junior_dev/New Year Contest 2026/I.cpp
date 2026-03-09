#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll mod = 998244353;

ll poww(ll x, ll y) {
    if (y == 0) return 1;
    else {
        ll k = poww(x, y/2);
        k *= k, k %= mod;
        if (y % 2 == 1) k *= x, k %= mod;
        return k;
    }
}

ll __lcm(ll x, ll y) { return x * y / __gcd(x, y); }

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll k, n, q; cin >> k >> n >> q;
    vector <pair <ll, ll>> v;
    int c = 0;
    for (int i = 0; i < q; i++) {
        string s = "AND"; ll x;
        if (i > 0) cin >> s;
        cin >> x;
        v.emplace_back(x, s == "OR");
        c = max(c, (int) (s == "OR"));
    }
    if (n == 1) {
        vector <
        return 0;
    }
    if (!c) {
        ll g = 1;
        for (auto &[x, y] : v) g = __lcm(x, g);
        ll ans = 0;
        for (int i = 1; i <= n; i++) if (i % g == 0) ans += poww(i, k), ans %= mod;
        cout << ans << '\n';
        return 0;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int s = 1;
        for (auto &[x, y] : v) {
            if (y == 1) s |= (i % x == 0);
            else s &= (i % x == 0);
        }
        if (s) ans += poww(i, k), ans %= mod;
    }
    cout << ans << '\n';
}

