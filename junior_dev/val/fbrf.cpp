// BRUTEFORCE
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll mod = 998244353;

ll poww(ll x, ll y) {
    if (y == 0) return 1;
    ll k = poww(x, y/2);
    k = (k*k)%mod;
    if (y % 2 == 1) k = (k*x)%mod;
    return k;
}

ll inv(ll x) {
    return poww(x, mod-2);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n;
    cin >> n;
    int a[n];
    for (auto &e : a) cin >> e;
    sort(a, a+n);
    ll ans = (n*n)%mod, cnt = 0;
    ans *= ans, ans %= mod;
    if (a[0] == a[n-1]) {cout << ans << '\n'; return 0;}
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) for (int k = 0; k < n; k++) for (int l = 0; l < n; l++) cnt += (abs(a[i]-a[j]) == abs(a[k] - a[l]));
    ans += cnt%mod, ans %= mod;
    ans *= inv(2), ans %= mod;
    cout << ans << '\n';
    cout << cnt << '\n';
}