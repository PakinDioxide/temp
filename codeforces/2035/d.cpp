#include <bits/stdc++.h>

using namespace std;

#define int long long

int mod = 1e9+7;

int poww(int x, int y) {
    if (y == 0) return 1;
    int k = (poww(x, y/2)) % mod;
    k = (k*k) % mod;
    if (y % 2 == 1) k *= x;
    return k % mod;
}

long double powww(long double x, int y) {
    if (y == 0) return 1;
    long double k = (poww(x, y/2));
    k = (k*k);
    if (y % 2 == 1) k *= x;
    return k;
}

pair <int, int> logg(int x) {
    int cnt = 0;
    while (x % 2 == 0) cnt++, x/=2;
    return {cnt, x};
}

void solve() {
    int n;
    cin >> n;
    int a[n+1], p[n+1], su[n+1], k[n+1], ans[n+1], vall[n+1];
    long double mx[n+1], val[n+1], anss[n+1];
    p[0] = su[0] = anss[0] = val[0] = vall[0] = ans[0] = 0;
    mx[0] = LLONG_MIN;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        p[i] = p[i-1], su[i] = su[i-1];
        pair <int, int> temp = logg(a[i]);
        p[i] += temp.first;
        su[i] += temp.second;
    }
    for (int i = 1; i <= n; i++) {
        if (mx[i-1] < (long double) p[i-1] + log2(a[i])) {
            mx[i] = (long double) p[i-1] + log2(a[i]);
            val[i] = (powww((long double) 2, p[i-1]) * a[i]);
            vall[i] = (poww(2, p[i-1]) * a[i]) % mod;
            k[i] = i;
        } else {
            mx[i] = mx[i-1];
            val[i] = val[i-1];
            vall[i] = vall[i-1];
            k[i] = k[i-1];
        }
        if (anss[i-1] + a[i] > su[k[i-1]] + val[i]) {
            anss[i] = anss[i-1] + a[i];
            ans[i] = (ans[i-1] + a[i]) % mod;
        } else {
            anss[i] = su[k[i-1]] + val[i];
            ans[i] = (su[k[i]-1] + vall[i]) % mod;
        }
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}