/*
    author  : PakinDioxide
    created : 27/03/2025 19:35
    task    : poruyraii
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll a[4][100005], dp[100005][4][4];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < 4; i++) for (int j = 1; j <= n; j++) cin >> a[i][j];
    ll ans = 0;
    for (int i = 1; i <= n/2; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                if (j == k) continue;
                ll mx = 0;
                for (int jj = 0; jj < 4; jj++) {
                    for (int kk = 0; kk < 4; kk++) {
                        if (j == jj || k == kk || jj == kk) continue;
                        mx = max(mx, dp[i-1][jj][kk]);
                    }
                }
                dp[i][j][k] = mx + a[j][i] + a[k][n-i+1];
                if (i == n/2) ans = max(ans, dp[i][j][k]);
            }
        }
    }
    cout << ans << '\n';
}