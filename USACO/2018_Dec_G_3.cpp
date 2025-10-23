/*
    author  : PakinDioxide
    created : 14/04/2025 14:28
    task    : 2018_Dec_G_3
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e4+5;

int n, k;
ll dp[mxN], a[mxN];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        ll mx = 0;
        for (int j = i; j > max(0, i-k); j--) mx = max(mx, a[j]), dp[i] = max(dp[i], dp[j-1] + (i-j+1)*mx);
    }
    cout << dp[n] << '\n';
}