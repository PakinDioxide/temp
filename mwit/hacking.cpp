#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll mod = 1e9+7, n, dp[2][5005];
string s;

int main() {
    cin >> n >> s;
    s = " " + s;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j >= 0; j--) {
            dp[i%2][j] = 0;
            if (j < i-j) break;
            if (s[i] == '_') {
                dp[i%2][j] = dp[(i+1)%2][j], dp[i%2][j] %= mod;
                if (j > 0) dp[i%2][j] += dp[(i+1)%2][j-1], dp[i%2][j] %= mod;
            } else if (s[i] == '0') {
                if (j > 0) dp[i%2][j] += dp[(i+1)%2][j-1], dp[i%2][j] %= mod;
            } else {
                dp[i%2][j] = dp[(i+1)%2][j], dp[i%2][j] %= mod;
            }
        }
    }
    cout << dp[n%2][n/2];
}