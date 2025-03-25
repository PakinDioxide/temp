/*
    author  : PakinDioxide
    created : 24/03/2025 20:54
    task    : 1639
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    a = ' ' + a, b = ' ' + b;
    int dp[n+1][m+1];
    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int i = 0; i <= m; i++) dp[0][i] = i;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        if (a[i] != b[j]) dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
        else dp[i][j] = dp[i-1][j-1];
    }
    cout << dp[n][m] << '\n';
}