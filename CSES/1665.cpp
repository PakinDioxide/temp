/*
    author  : PakinDioxide
    created : 26/04/2025 00:23
    task    : 1665
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll dp[2][20005], ofs = 10000, mod = 1e9+7;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, x;
    cin >> n >> x;
    dp[0][ofs] = 1;
    for (int i = 1; i <= n; i++) {
        int e;
        cin >> e;
        for (int j = 0; j <= 20000; j++) dp[i&1][j] = ((j >= e ? dp[!(i&1)][j-e] : 0) + (j+e <= 20000 ? dp[!(i&1)][j+e] : 0)) % mod;
    }
    ll ans = 0;
    for (int j = 0; j <= x; j++) ans += dp[n&1][j+ofs], ans %= mod;
    cout << ans << '\n';
}