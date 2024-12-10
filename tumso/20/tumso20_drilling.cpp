#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    ll a[n+1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector <vector <ll>> dp(2, vector <ll>(n+1)), c(2, vector <ll>(n+1)), o(2, vector <ll>(n+1));
    for (int x = 1; x <= k; x++) {
        int i = x%2, ii = (x+1)%2;
        for (int j = 1; j <= n; j++) {
            c[i][j] = dp[i][j] = o[i][j] = 0;
            if (j < x) continue;
            if (x == j) {
                c[i][j] = a[j];
                dp[i][j] = dp[ii][j-1] + c[i][j];
                o[i][j] = dp[ii][j-1];
                continue;
            }
            c[i][j] = max(a[j], c[i][j-1]);
            dp[i][j] = o[i][j-1] + c[i][j];
            o[i][j] = o[i][j-1];
            if (x > 1) {
                if (dp[ii][j] + a[j] < dp[i][j]) {
                    dp[i][j] = dp[ii][j] + a[j];
                    c[i][j] = a[j];
                    o[i][j] = dp[ii][j];
                }
            }
        }

    }
    // for (int i = 1; i <= k; i++) {
    //     for (int j = 1; j <= n; j++) cout << dp[i][j] << ' ';
    //     cout << '\n';
    // }
    cout << dp[k%2][n];
}