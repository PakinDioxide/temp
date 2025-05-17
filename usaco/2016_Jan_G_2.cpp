/*
    author  : PakinDioxide
    created : 29/04/2025 23:43
    task    : 2016_Jan_G_2
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    // freopen("radio.in", "r", stdin);
    // freopen("radio.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector <pair <int, int>> a(n+2), b(m+2);
    map <char, pair <int, int>> mp;
    mp['N'] = {0, 1}, mp['S'] = {0, -1}, mp['W'] = {-1, 0}, mp['E'] = {1, 0};
    cin >> a[1].first >> a[1].second >> b[1].first >> b[1].second;
    string p, q; cin >> p >> q;
    for (int i = 0; i < n; i++) a[i+2].first += a[i+1].first + mp[p[i]].first, a[i+2].second += a[i+1].second + mp[p[i]].second;
    for (int i = 0; i < m; i++) b[i+2].first += b[i+1].first + mp[q[i]].first, b[i+2].second += b[i+1].second + mp[q[i]].second;
    n++, m++;
    auto calc = [&] (pair <int, int> x, pair <int, int> y) { return (ll) (pow(x.first-y.first, 2) + pow(x.second-y.second, 2)); };
    ll dp[n+1][m+1];
    for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++) dp[i][j] = INT_MAX;
    dp[1][1] = 0;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        if (i > 1) dp[i][j] = min(dp[i][j], dp[i-1][j] + calc(a[i], b[j]));
        if (j > 1) dp[i][j] = min(dp[i][j], dp[i][j-1] + calc(a[i], b[j]));
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cout << dp[i][j] << ' ';
        cout << '\n';
    }
    cout << dp[n][m] << '\n';
}