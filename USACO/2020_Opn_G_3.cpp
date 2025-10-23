#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector <ll> pr;

bool ip(ll x) {
    if (x <= 1) return 0;
    for (auto &e : pr) {
        if (e*e > x) break;
        if (x % e == 0) return 0;
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("exercise.in", "r", stdin);
    freopen("exercise.out", "w", stdout);
    ll n, mod;
    cin >> n >> mod;
    for (int i = 1; i <= n; i++) if (ip(i)) pr.emplace_back(i);
    ll dp[2][n+1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 0; i < pr.size(); i++) {
        for (int j = n; j >= 0; j--) dp[!(i&1)][j] = dp[i&1][j];
        int k = 1;
        for (int c = 1; k*pr[i] <= n; c++) {
            k *= pr[i];
            for (int j = n; j >= k; j--) dp[!(i&1)][j] += dp[i&1][j-k] * k, dp[!(i&1)][j] %= mod;
        }
    }
    ll ans = 0;
    for (int i = 0; i <= n; i++) ans += dp[pr.size()&1][i], ans %= mod;
    cout << ans << '\n';
}

/*
maximum lcm is n*n
*/