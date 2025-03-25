/*
    author  : PakinDioxide
    created : 13/03/2025 13:05
    task    : c2_su65_chocolate
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll mod = 1e9+7;

ll poww(ll x, ll y) {
    if (y == 0) return 1;
    ll k = poww(x, y/2);
    k *= k;
    if (y & 1LL) k *= x;
    return k;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, k, c;
    cin >> n >> k >> c;
    ll a[n], lo, hi, dp[n+5][2];//, pdp[n+5][n+5];
    memset(dp, 0, sizeof(dp));
    for (auto &e : a) cin >> e;
    cin >> lo >> hi;
    dp[n][0] = 1;
    // for (int i = 0; i < n; i++) {
    //     pdp[i][i] = poww(0, c)*a[i];
    //     for (int j = i+1; j < n; j++) pdp[i][j] = pdp[i][j-1] + poww(j-i, c) * a[j];
    // }
    pair <ll, ll> idx[n];
    // check idx1 and idx2 for each i first
    for (int i = n-1; i >= 0; i--) {
        // create pdp
        ll pdp[n+1];
        pdp[i] = poww(0, c)*a[i];
        for (int j = i+1; j < n; j++) pdp[j] = pdp[j-1] + poww(j-i, c) * a[j];
        // bsearch for idx1, idx2
        ll idx1 = lower_bound(pdp+i, pdp+n, lo) - pdp;
        ll idx2 = upper_bound(pdp+i, pdp+n, hi) - pdp - 1;
        // store idx1, idx2
        idx[i] = {idx1, idx2};
    }
    // for (auto [idx1, idx2] : idx) cerr << idx1 << ' ' << idx2 << '\n';
    // do dp
    for (int l = 0; l <= k; l++) {
        for (int i = 0; i <= n; i++) dp[i][!(l&1)] = 0;
        for (int i = n-1; i >= 0; i--) {
            // add pref sum
            dp[i][l&1] += dp[i+1][l&1], dp[i][l&1]%=mod;
            // get idx1, idx2
            auto [idx1, idx2] = idx[i];
            if (idx1 > idx2 || l == k) continue;
            // add val
            dp[i][!(l&1)] += (dp[idx1+1][l&1] - dp[idx2+2][l&1] + mod) % mod, dp[i][!(l&1)] %= mod;
        }
    }
    // for (int i = n-1; i >= 0; i--) {
    //     ll idx1 = lower_bound(pdp[i]+i, pdp[i]+n, lo) - pdp[i];
    //     ll idx2 = upper_bound(pdp[i]+i, pdp[i]+n, hi) - pdp[i] - 1;
    //     for (int l = 0; l <= k; l++) dp[i][l] += dp[i+1][l];
    //     if (idx1 > idx2) continue;
    //     for (int l = 0; l < k; l++) dp[i][l+1] += (dp[idx1+1][l] - dp[idx2+2][l]);
    // }
    cout << (dp[0][k&1]-dp[1][k&1]+mod)%mod << '\n';
}