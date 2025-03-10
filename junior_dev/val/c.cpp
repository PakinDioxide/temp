#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll mod = 1e9+7;

ll poww(ll x, ll y) {
    if (y == 0) return 1;
    ll k = poww(x, y/2);
    k = (k*k)%mod;
    if (y % 2 == 1) k = (k*x)%mod;
    return k;
}

void solve() {
    ll n;
    cin >> n;
    if (n == 1) {cout << 0 << '\n'; return;}
    ll ans = 0;
    ans += (2*((((n-1)%mod)*poww(3, n-2)) % mod))%mod;
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}