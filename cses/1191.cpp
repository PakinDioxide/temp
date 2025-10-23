/*
    author  : 
    created : 14/07/2025
    task    : 1687_2
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5, mxL = 20;

int n, dp[mxL][2*mxN];
ll k, a[2*mxN];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i], a[i+n] = a[i];
    int l = 0;
    for (int i = 1; i <= 2*n; i++) {
        a[i] += a[i-1];
        while (a[i] - a[l] > k) l++;
        dp[0][i] = l;
    }
    for (int c = 1; c < mxL; c++) for (int i = 1; i <= 2*n; i++) dp[c][i] = dp[c-1][dp[c-1][i]];
    int mn = INT_MAX;
    for (int i = n; i <= 2*n; i++) {
        int u = i, cnt = 0;
        for (int c = mxL-1; c >= 0; c--) if (dp[c][u] > i-n) u = dp[c][u], cnt |= (1 << c);
        mn = min(mn, cnt+1);
    }
    cout << mn << '\n';
}