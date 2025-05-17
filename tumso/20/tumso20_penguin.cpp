/*
    author  : PakinDioxide
    created : 05/05/2025 09:56
    task    : tumso20_penguin
*/
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

void solve() {
    ll n;
    cin >> n;
    cout << (poww(2, n) - n % mod + mod) % mod << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}