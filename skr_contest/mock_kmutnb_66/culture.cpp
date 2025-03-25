/*
    author  : PakinDioxide
    created : 25/03/2025 19:55
    task    : culture
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    ll a[n+1][2*n+1], dp[n+1][2*n+1], p[n+1][2*n+1];
    memset(a, 0, sizeof(a));
    memset(dp, 0, sizeof(dp));
    memset(p, 0, sizeof(p));
    for (int i = 0; i < m; i++) {
        int x, y; ll s;
        cin >> x >> y >> s;
        a[x][y+n] += s;
    }
    ll ans = 0, idx = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = n-i; j <= n+i; j++) {
            if (j > n-i && j < n+i) if (dp[i][j] <= dp[i-1][j]) dp[i][j] = dp[i-1][j], p[i][j] = 0;
            if (j > n-i+1) if (dp[i][j] <= dp[i-1][j-1]) dp[i][j] = dp[i-1][j-1], p[i][j] = 1;
            if (j < n+i-1) if (dp[i][j] <= dp[i-1][j+1]) dp[i][j] = dp[i-1][j+1], p[i][j] = -1;
            dp[i][j] += a[i][j];
            if (i == n && dp[i][j] >= ans) ans = dp[i][j], idx = j;
        }
    }
    cout << ans << '\n';
    int q;
    cin >> q;
    if (q) {
        stack <int> ans;
        int x = n, y = idx;
        while (x != 0 || y != n) {
            int k = p[x][y];
            ans.push(k);
            x--, y-=k;
        }
        while (!ans.empty()) cout << ans.top() << ' ', ans.pop();
        cout << '\n';
    }
}