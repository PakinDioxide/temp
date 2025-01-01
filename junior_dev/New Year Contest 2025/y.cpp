// PakinDioxide - Bruteforce
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll mod = 1e9+7;

ll poww(ll x, ll y) {
    if (y == 0) return 1;
    ll k = poww(x, y/2) % mod;
    k*=k, k %= mod;
    if (y%2) k*=x, k %= mod;
    return k;
}

ll mult(ll x, ll y) {
    if (y == 0) return 0;
    ll k = mult(x, y/2) % mod;
    k += k; k %= mod;
    if (y%2) k+=x, k %= mod;
    return k;
}

ll inv(ll x) {
    return poww(x, mod-2);
}

void solve() {
    ll a, b, x, y;
    cin >> a >> b >> x >> y;
    ll p = 0, q = 0;

    if (a == 1) x%=mod, p = (((x*((x+1)%mod))%mod)*inv(2))%mod;
    else if (a == 2) x%=mod, p = (((((x*((x+1)%mod))%mod)*(((2*x)%mod)+1))%mod)*inv(6))%mod;
    else if (a == 3) x%=mod, p = poww((((x*((x+1)%mod))%mod)*inv(2))%mod, 2);
    else for (ll i = 1; i <= x; i++) p += poww(i, a), p %= mod;

    if (b == 1) y%=mod, q = (((y*((y+1)%mod))%mod)*inv(2))%mod;
    else if (b == 2) y%=mod, q = (((((y*((y+1)%mod))%mod)*(((2*y)%mod)+1))%mod)*inv(6))%mod;
    else if (b == 3) y%=mod, q = poww((((y*((y+1)%mod))%mod)*inv(2))%mod, 2);
    else for (ll i = 1; i <= y; i++) q += poww(i, b), q %= mod;

    cout << (p*q)%mod << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}