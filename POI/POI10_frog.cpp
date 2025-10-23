/*
    author  : 
    created : 14/07/2025 20:31
    task    : POI10_frog
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e6+5, mxL = 62;

int n, k, dp[2][mxN], ans[mxN];
ll m, a[mxN];


int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int l = 1, r = k+1;
    for (int i = 1; i <= n; i++) {
        while (r+1 <= n && a[r+1] - a[i] < a[i] - a[l]) r++, l++;
        dp[0][i] = (a[i] - a[l] >= a[r] - a[i] ? l : r);
    }
    for (int i = 1; i <= n; i++) ans[i] = i;
    for (int c = 0; c < mxL; c++) {
        if (c > 0) for (int i = 1; i <= n; i++) dp[c&1][i] = dp[!(c&1)][dp[!(c&1)][i]];
        if (m & (1LL << c)) for (int i = 1; i <= n; i++) ans[i] = dp[c&1][ans[i]];
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << ' '; cout << '\n';
}