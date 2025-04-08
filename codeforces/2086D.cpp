/*
    author  : PakinDioxide
    created : 03/04/2025 22:05
    task    : 2086D
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll mod = 998244353;

ll poww(ll x, ll y) {
    if (y == 0) return 1;
    ll k = poww(x, y/2);
    k *= k, k %= mod;
    if (y % 2 == 1) k *= x, k %= mod;
    return k;
}

ll inv(ll x) {
    return poww(x, mod-2);
}

ll fac(ll x) {
    ll sum = 1;
    for (ll i = x; i >= 1; i--) sum *= i, sum %= mod;
    return sum;
}

void solve() {
    ll n = 26, a[26], sum = 0;
    for (auto &e : a) cin >> e, sum += e;
    ll dp[sum/2+1];
    ll ans = 0, o = fac(sum/2), e = fac((ll) ceil(sum/2.0));
    memset(dp, 0, sizeof(dp));
    dp[0] = (o*e) % mod;
    for (short i = 0; i < n; i++) {
        if (a[i] == 0) continue;
        ll k = inv(fac(a[i]));
        for (int j = sum/2; j >= 0; j--) {
            dp[j] *= k, dp[j] %= mod;
            if (j >= a[i]) dp[j] += (dp[j-a[i]] * k), dp[j] %= mod;
        }
        // for (int j = 0; j <= sum/2; j++) cout << dp[j] << ' ';
        // cout << '\n';
    }
    // for (auto E : dp[sum/2]) {
    //     short vis[n];
    //     for (auto &e : E) if (e >= 0) vis[e] = 1;
    //     ll k1 = o, k2 = e;
    //     for (short i = 0; i < n; i++) {
    //         if (vis[i]) k1 *= inv(fac(a[i])), k1 %= mod;
    //         else k2 *= inv(fac(a[i])), k2 %= mod;
    //     }
    //     ans += (k1 * k2) % mod, ans %= mod;
    // }
    // cout << ans << '\n';
    cout << dp[sum/2] << '\n';
    // if (sum % 2 == 0) cout << (dp[sum/2]*inv(2))%mod << '\n';
    // else cout << dp[sum/2] << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}