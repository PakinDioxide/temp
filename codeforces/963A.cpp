#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll mod = 1e9+9;

ll poww(ll x, ll y) {
    y %= mod-1;
    if (y == 0) return 1;
    ll k = poww(x, y/2);
    k *= k, k %= mod;
    if (y % 2 == 1) k *= x, k %= mod;
    return k;
}

ll inv(ll x) { return poww(x, mod-2); }

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n, a, b, k;
    cin >> n >> a >> b >> k;
    ll T = 0;
    string s; cin >> s;
    for (int i = 0; i < k; i++) {
        ll k = (s[i] == '+' ? 1 : -1);
        T += (((poww(a, n-i) * poww(b, i)) % mod) * k + mod) % mod;
        T %= mod;
    }
    ll X = (inv(poww(a, k)) * poww(b, k)) % mod;
    ll Y = (poww(X, (n+1)/k) - 1 + mod) % mod;
    Y *= inv(X - 1), Y %= mod;
    if (X == 1) Y = (n+1)/k;
    cout << ((T * Y) % mod + mod) % mod << '\n';
}

