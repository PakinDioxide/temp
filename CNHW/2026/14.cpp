#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll mod;

ll poww(ll x, ll y) {
    if (y == 0) return 1;
    ll k = poww(x, y/2);
    k *= k, k %= mod;
    if (y % 2 == 1) k *= x, k %= mod;
    return k;
}

ll inv(ll x) { return poww(x, mod-2); }

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m; cin >> n >> m >> mod;
    ll val; cin >> val;
    ll x = val;
    for (int i = 1; i <= n; i++) x *= inv(i), x %= mod;
    for (int i = 1; i <= m; i++) x *= inv(i), x %= mod;
    cout << x << '\n';
}

