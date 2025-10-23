/*
    author  : PakinDioxide
    created : 14/04/2025 14:13
    task    : 2017_Jan_G_2
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5, mxK = 25;

int n, k, dp[mxK][mxN][3], mx = 0;
char a[mxN];
map <int, char> mp;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    mp[0] = 'S';
    mp[1] = 'H';
    mp[2] = 'P';
    for (int i = 1; i <= n; i++) for (int j = 0; j < 3; j++) dp[0][i][j] = dp[0][i-1][j] + (a[i] == mp[j]), mx = max(mx, dp[0][i][j]);
    for (int o = 1; o <= k; o++) for (int i = 1; i <= n; i++) for (int j = 0; j < 3; j++) {
        dp[o][i][j] = dp[o][i-1][j];
        for (int jj = 0; jj < 3; jj++) dp[o][i][j] = max(dp[o][i][j], dp[o-1][i-1][jj]);
        dp[o][i][j] += (a[i] == mp[j]);
        mx = max(mx, dp[o][i][j]);
    }
    cout << mx << '\n';
}