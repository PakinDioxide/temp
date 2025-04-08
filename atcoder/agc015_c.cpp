/*
    author  : PakinDioxide
    created : 05/04/2025 00:28
    task    : agc015_c
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    int a[n+1][m+1];
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        s = ' ' + s;
        for (int j = 1; j <= m; j++) a[i][j] = (s[j] == '1');
    }
    int dp[n+1][m+1], dpx[n+1][m+1], dpy[n+1][m+1];
    memset(dp, 0, sizeof(dp));
    memset(dpx, 0, sizeof(dpx));
    memset(dpy, 0, sizeof(dpy));
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        dpx[i][j] = dpx[i-1][j];
        dpy[i][j] = dpy[i][j-1];
        if (a[i][j]) {
            if (a[i-1][j] == 0 && a[i][j-1] == 0) dp[i][j]++;
            if (a[i-1][j] == 1 && a[i][j-1] == 1) dp[i][j]--;
            dpx[i][j] += !(a[i-1][j]);
            dpy[i][j] += !(a[i][j-1]);
        }
    }
    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int ans = 0;
        ans += dpx[x2][y1] - dpx[(x1+1)-1][y1];
        ans += dpy[x1][y2] - dpy[x1][(y1+1)-1];
        ans += a[x1][y1];
        ans += dp[x2][y2] - dp[x2][y1] - dp[x1][y2] + dp[x1][y1];
        cout << ans << '\n';
    }

}