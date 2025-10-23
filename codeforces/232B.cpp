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

ll inv(ll x) { return poww(x, mod-2); }

ll ncr(ll x, ll y) {
    ll s = 1;
    if (y == 0) return 1;
    for (int i = 1; i <= x; i++) s *= i, s %= mod;
    for (int i = 1; i <= y; i++) s *= inv(i), s %= mod;
    for (int i = 1; i <= x-y; i++) s *= inv(i), s %= mod;
    return s;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n, m, k; cin >> n >> m >> k;
    ll dp[n+1][k+1], NCR[n+1]; memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= n; i++) NCR[i] = ncr(n, i);
    ll p[2][n+1]; 
    for (int i = 0; i <= n; i++) p[0][i] = poww(NCR[i], m/n+1);
    for (int i = 0; i <= n; i++) p[1][i] = poww(NCR[i], m/n);
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) for (int j = 0; j <= k; j++) {
        dp[i][j] = 0;
        for (int x = 0; x <= min(j, (int) n); x++) dp[i][j] += (dp[i-1][j-x] * (i <= (m % n) ? p[0][x] : p[1][x])) % mod, dp[i][j] %= mod;
    }
    cout << dp[n][k] << '\n';
}

/*
if column i has p points, then column i+n must have p points
*/