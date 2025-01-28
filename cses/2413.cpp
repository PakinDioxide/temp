#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll mxN = 1e6;
ll dp[mxN+5][2], mod = 1e9+7;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    dp[0][0] = dp[0][1] = 0;
    dp[1][0] = 1, dp[1][1] = 1;
    for (int i = 2; i <= mxN; i++) {
        dp[i][0] = (2*dp[i-1][0])%mod + dp[i-1][1];
        dp[i][1] = dp[i-1][0] + (4*dp[i-1][1])%mod;
        dp[i][0] %= mod, dp[i][1] %= mod;
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << (dp[n][0] + dp[n][1])%mod << '\n';
    }
}