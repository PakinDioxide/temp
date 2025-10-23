/*
    author  : PakinDioxide
    created : 11/03/2025 19:42
    task    : 1097
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    ll a[n];
    for (auto &e : a) cin >> e;
    ll dp[n][n];
    for (int i = 0; i < n; i++) dp[i][i] = (n%2)*a[i];
    for (int l = 1; l < n; l++) {
        for (int i = 0; i+l < n; i++) {
            int j = i+l;
            if ((n+l)%2 == 1) dp[i][j] = max(dp[i][j-1] + a[j], dp[i+1][j] + a[i]);
            else dp[i][j] = min(dp[i][j-1], dp[i+1][j]);
        }   
    }
    cout << dp[0][n-1] << '\n';
}