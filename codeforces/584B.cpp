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

int main() {
    ll n;
    cin >> n;
    cout << ((poww(3, 3*n) - poww(7, n)) % mod + mod) % mod << '\n';
}
