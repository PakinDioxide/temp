#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n;
    cin >> n;
    ll dp[n][n];
    string s[n];
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = 0;
            if (s[i][j] == '*') continue;
            if (i == 0 && j == 0) dp[i][j] = 1;
            if (i > 0) dp[i][j] += dp[i-1][j];
            if (j > 0) dp[i][j] += dp[i][j-1];
            dp[i][j] %= 1000000007;
        }
    }
    cout << dp[n-1][n-1];
}