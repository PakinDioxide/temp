/*
    author  : PakinDioxide
    created : 17/03/2025 18:29
    task    : 1744
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int vis[505][505], dp[505][505];

int solve(int n, int m) {
    if (n > m) swap(n, m);
    if (vis[n][m]) return dp[n][m];
    vis[n][m] = 1;
    if (n == m) return dp[n][m] = 0;
    int mn = INT_MAX;
    for (int i = 1; i < n; i++) mn = min(mn, solve(i, m) + solve(n-i, m) + 1);
    for (int i = 1; i < m; i++) mn = min(mn, solve(n, i) + solve(n, m-i) + 1);
    return dp[n][m] = mn;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    cout << solve(n, m) << '\n';   
}