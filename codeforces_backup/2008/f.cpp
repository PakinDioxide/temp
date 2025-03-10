#include <bits/stdc++.h>

using namespace std;

#define int long long

int mod = 1e9+7;

int poww(int x, int y) {
    if (y == 1) return x;
    int k = poww(x, y/2);
    return (((k * k) % mod) * (y % 2 == 1 ? x : 1)) % mod;
}

void solve() {
    int n;
    scanf("%lld", &n);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    int sum = a[0], ans = 0;
    for (int i = 1; i < n; i++) {
        ans += sum * a[i];
        sum += a[i];
        sum %= mod;
        ans %= mod;
    }
    int cnt = n*(n-1)/2;
    printf("%lld\n", ((ans % mod) * poww(cnt % mod, mod-2)) % mod);
} 

int32_t main() {
    int t;
    scanf("%lld", &t);
    while (t--) solve();
}