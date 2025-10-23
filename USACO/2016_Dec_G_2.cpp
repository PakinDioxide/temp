/*
    author  : PakinDioxide
    created : 29/04/2025 20:17
    task    : 2016_Dec_G_2
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("checklist.in", "r", stdin);
    freopen("checklist.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    ll dp[n+1][m+1][2]; // i, j end 0, 1
    vector <vector<pair <int, int>>> a(2, vector <pair <int, int>>(max(n, m)+1));
    for (int i = 1; i <= n; i++) cin >> a[0][i].first >> a[0][i].second;
    for (int i = 1; i <= m; i++) cin >> a[1][i].first >> a[1][i].second;
    auto calc = [&] (pair <int, int> x, pair <int, int> y) { return (ll) (pow(x.first-y.first, 2) + pow(x.second-y.second, 2)); };
    for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++) dp[i][j][0] = dp[i][j][1] = INT_MAX;
    dp[1][0][0] = 0;
    for (int i = 1; i <= n; i++) for (int j = 0; j <= m; j++) {
        if (i == 1 && j == 0) continue;
        if (i > 1) dp[i][j][0] = min({dp[i][j][0], dp[i-1][j][0] + calc(a[0][i-1], a[0][i]), (j > 0 ? dp[i-1][j][1] + calc(a[1][j], a[0][i]) : INT_MAX)});
        if (j > 0) dp[i][j][1] = min({dp[i][j][1], dp[i][j-1][0] + calc(a[0][i], a[1][j]), (j > 1 ? dp[i][j-1][1] + calc(a[1][j-1], a[1][j]) : INT_MAX)});
    }
    cout << dp[n][m][0] << '\n';
}