#include <bits/stdc++.h>

using namespace std;

int gcd(int x, int y) {if (y == 0) return x; else return gcd(y, x%y);}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n][m], dp[n][m];
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
        dp[0][0] = a[0][0];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) continue;
                dp[i][j] = 0;
                if (i > 0) dp[i][j] = max(dp[i][j], gcd(a[i][j], dp[i-1][j]));
                if (j > 0) dp[i][j] = max(dp[i][j], gcd(a[i][j], dp[i][j-1]));
            }
        }
        cout << dp[n-1][m-1] << '\n';
    }
}