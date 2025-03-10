#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll dp[205][205][500], mod = 1e7+9;
char a[205][205];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, r;
    cin >> n >> m >> r;
    for (int i = 0; i < n; i++) cin >> a[i];
    dp[0][0][0] = (a[0][0] == '.');
    dp[0][0][1] = (a[0][0] == 'X');
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '#' || (i == 0 && j == 0)) continue;
            if (a[i][j] == '.') {
                for (int k = 0; k <= r; k++) {
                    if (i-1 >= 0) dp[i][j][k] += dp[i-1][j][k];
                    if (j-1 >= 0) dp[i][j][k] += dp[i][j-1][k];
                    dp[i][j][k] %= mod;
                }
            } else {
                for (int k = 1; k <= r; k++) {
                    if (i-1 >= 0) dp[i][j][k] += dp[i-1][j][k-1];
                    if (j-1 >= 0) dp[i][j][k] += dp[i][j-1][k-1];
                    dp[i][j][k] %= mod;
                }
            }
        }
    }
    ll sum = 0;
    for (int i = 0; i <= r; i++) sum += dp[n-1][m-1][i], sum %= mod;
    cout << sum << '\n';
}