/*
    author  : PakinDioxide
    created : 11/04/2025 23:53
    task    : COCI17_kas
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    ll a[n+1], s = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], s += a[i];
    ll dp[2][200005];
    for (int i = 0; i <= 200000; i++) dp[0][i] = LLONG_MIN;
    dp[0][100000] = 0;
    for (int i = 1; i <= n; i++) { for (int j = 200000; j >= 0; j--) dp[i&1][j] = max({dp[!(i&1)][j], (j+a[i] <= 200000 ? dp[!(i&1)][j+a[i]] + a[i] : LLONG_MIN), (j-a[i] >= 0 ? dp[!(i&1)][j-a[i]] : LLONG_MIN)}); }
    cout << s - dp[n&1][100000] << '\n';
}