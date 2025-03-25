/*
    author  : PakinDioxide
    created : 20/03/2025 03:20
    task    : 04
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll mod = 1e9+7, dp[150000];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    int a[n], k = 0;
    for (auto &e : a) cin >> e, k |= e;
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (auto &e : a) for (int i = k; i >= 0; i--) if (i | e <= k) dp[i|e] = (dp[i|e] + dp[i])%mod;
    cout << dp[k] << '\n';
}