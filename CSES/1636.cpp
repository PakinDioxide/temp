/*
    author  : PakinDioxide
    created : 20/03/2025 03:18
    task    : 1636
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n >> k;
    ll dp[k+1], a[n], mod = 1e9+7;
    for (auto &e : a) cin >> e;
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (auto &e : a) for (int i = e; i <= k; i++) dp[i] = (dp[i] + dp[i-e]) % mod;
    cout << dp[k] << '\n';
}