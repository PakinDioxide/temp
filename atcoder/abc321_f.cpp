/*
    author  : PakinDioxide
    created : 24/03/2025 18:17
    task    : abc321_f
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int q, k;
    cin >> q >> k;
    ll dp[k+1], mod = 998244353;
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    while (q--) {
        char o;
        int e;
        cin >> o >> e;
        if (o == '+') {
            for (int i = k; i >= e; i--) dp[i] += dp[i-e], dp[i] %= mod;
        } else {
            for (int i = e; i <= k; i++) dp[i] -= dp[i-e], dp[i] = (dp[i] + mod) % mod;
        }
        cout << dp[k] << '\n';
    }
}