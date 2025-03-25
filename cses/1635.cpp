/*
    author  : PakinDioxide
    created : 20/03/2025 03:15
    task    : 1635
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
    for (int i = 1; i <= k; i++) for (auto &e : a) if (i >= e) dp[i] = (dp[i] + dp[i-e]) % mod;
    cout << dp[k] << '\n';
}