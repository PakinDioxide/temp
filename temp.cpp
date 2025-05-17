/*
    author  : PakinDioxide
    created : 14/05/2025 15:18
    task    : temp
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    vector <int> a(n);
    for (auto &e : a) cin >> e;
    ll dp[5][n+1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= n; i++) dp[0][i] = 1;
    for (int i = 1; i <= 4; i++) for (int j = i; j <= n; j++) dp[i][j] = dp[i-1][j-1] * a[j-1] + dp[i][j-1];
}

/*

*/