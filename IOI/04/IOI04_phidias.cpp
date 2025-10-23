/*
    author  : PakinDioxide
    created : 15/04/2025 14:46
    task    : IOI04_phidias
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int w, h, n;
    cin >> w >> h >> n;
    ll dp[w+1][h+1];
    for (int i = 0; i <= w; i++) for (int j = 0; j <= h; j++) dp[i][j] = i*j;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        dp[x][y] = 0;
    }
    for (int i = 1; i <= w; i++) for (int j = 1; j <= h; j++) {
        for (int x = 1; x < i; x++) dp[i][j] = min(dp[i][j], dp[x][j] + dp[i-x][j]);
        for (int y = 1; y < j; y++) dp[i][j] = min(dp[i][j], dp[i][y] + dp[i][j-y]);
    }
    cout << dp[w][h] << '\n';
}