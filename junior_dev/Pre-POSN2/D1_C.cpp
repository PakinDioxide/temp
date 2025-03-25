/*
    author  : PakinDioxide
    created : 15/03/2025 18:54
    task    : D1_C
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    ll a[n][m+1];
    for (int i = 0; i < n; i++) for (int j = 1; j <= m; j++) cin >> a[i][j];
    ll dp[n+1][m+1];
    for (int i = 0; i < n; i++) for (int j = 1; j <= m; j++) dp[i][j] = (i == n-1 ? a[i][j] : LLONG_MIN);
    for (int i = n-2; i >= 0; i--) {
        ll p[m+1], r[m+2], l[m+1];
        p[0] = 0;
        l[0] = r[m+1] = LLONG_MIN;
        for (int j = 1; j <= m; j++) p[j] = p[j-1] + a[i][j];
        for (int j = 1; j <= m; j++) l[j] = max(l[j-1], dp[i+1][j] + p[m] - p[j-1]);
        for (int j = m; j > 0; j--) r[j] = max(r[j+1], p[j] + dp[i+1][j]);
        // cout << "L ";
        // for (int j = 1; j <= m; j++) cout << l[j] << ' ';
        // cout << '\n' << "R ";
        // for (int j = 1; j <= m; j++) cout << r[j] << ' ';
        // cout << '\n';
        for (int j = 1; j <= m; j++) dp[i][j] = max(l[j] - p[m] + p[j], r[j] - p[j-1]);//, cout << dp[i][j] << ' ';
        // cout << '\n';
    }
    for (int i = 1; i <= m; i++) cout << dp[0][i] << ' ';
    cout << '\n';
}