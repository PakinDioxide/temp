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
    for (int d = 0; d <= a[n-1] - a[0]; d++) {
        int r = 0;
        ll c = 0;
        for (int l = 0; l < n; l++) {
            while (r < n && a[r] - a[l] < d) r++;
            int st = r;
            while (a[r] - a[l] == d) r++;
            if (d == 0) c += r-st, c += ((r-st)*(r-st-1))%mod;
            else c += 2*(r-st);
            c %= mod;
        }
        cnt += (c*c)%mod;
        cnt %= mod;
    }
    // cout << cnt << '\n';
    ans += cnt%mod, ans %= mod;
    ans *= inv(2), ans %= mod;
    cout << ans << '\n';
}

// cout << i << ' ' << l << ' ' << j << ' ' << r << " - " << (1+(i!=l))*(1+(j!=r))*(1+(i!=j||l!=r)) << '\n',