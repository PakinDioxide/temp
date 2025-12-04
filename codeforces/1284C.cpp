#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n, m;

ll poww(ll x, ll y) {
    if (y == 0) return 1;
    ll k = poww(x, y/2);
    k *= k, k %= m;
    if (y % 2 == 1) k *= x, k %= m;
    return k;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    ll ans = 0, f[n+1]; f[0] = f[1] = 1;
    for (int i = 2; i <= n; i++) f[i] = (f[i-1] * i) % m;
    for (int i = 1; i <= n; i++) ans += (((poww(n-i+1, 2) * f[i]) % m) * f[n-i]) % m, ans %= m;
    cout << ans << '\n';
}