#include <bits/stdc++.h>
#define ll long long

using namespace std;

int q, m, ans = 0;

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int dp[n][n], cl[n][n], cr[n][n], sm[n][n];
    // memset(dp, 0, sizeof(dp));
    // memset(cl, 0, sizeof(cl));
    // memset(cr, 0, sizeof(cr));
    // memset(sm, 0, sizeof(sm));
    for (int i = 0; i < n; i++) dp[i][i] = cl[i][i] = cr[i][i] = sm[i][i] = 1;
    for (int l = 1; l < n; l++) {
        for (int i = 0; i+l < n; i++) {
            int j = i+l;
            dp[i][j] = INT_MAX;
            sm[i][j] = 1;
            for (int k = i; k < j; k++) sm[i][j] = min(sm[i][j], (int) (a[i] == a[i+1]));
            for (int k = i; k < j; k++) {
                // cout << i << ' ' << k << ' ' << k+1 << ' ' << j << '\n';
                // cout << "CL " << cl[i][k] << '\n';
                // cout << "CR " << cr[k+1][j] << '\n';
                int sum = dp[i][k] + dp[k+1][j], mg = 0;
                if (a[k] == a[k+1] && cr[i][k] + cl[k+1][j] <= m) sum--, mg = 1;
                if (dp[i][j] > sum) {
                    dp[i][j] = sum;
                    cl[i][j] = cl[i][k], cr[i][j] = cr[k+1][j];
                    if (mg) {
                        if (sm[i][k]) cl[i][j] += cl[k+1][j];
                        if (sm[k+1][j]) cr[i][j] += cr[i][k];
                    }
                }
                // cout << mg << '\n';
            }
        }
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) cout << dp[i][j] << ' ';
    //     cout << '\n';
    // }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) cout << sm[i][j] << ' ';
    //     cout << '\n';
    // }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) cout << "(" << cl[i][j] << ", " << cr[i][j] << "), ";
    //     cout << '\n';
    // }
    // cout << dp[0][n-1] << '\n';
    ans = max(ans, dp[0][n-1]);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> q >> m;
    while (q--) solve();
    cout << ans << '\n';
}