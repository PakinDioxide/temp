/*
    author  : 
    created : 01/07/2025 22:37
    task    : 2123E
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    int a[n];
    for (auto &e : a) cin >> e;
    sort(a, a+n); int idx = 0, mex = 0;
    int p[n+4];
    memset(p, 0, sizeof(p));
    for (int i = 0; i <= n+5; i++) {
        int ok = 0;
        while (idx < n && a[idx] == i) ok = 1, p[a[idx]]++, idx++;
        if (!ok) { mex = i; break; }
    }
    int ccc = 0;
    for (auto &e : a) if (e > mex) ccc++;
    for (int i = 1; i < n+4; i++) p[i] = p[i] + p[i-1];
    // for (int i = 0; i <= mex; i++) cout << p[i] << ' ';
    // cout << '\n';
    int dp[n+1], cc[n+4]; memset(dp, 0, sizeof(dp)); memset(cc, 0, sizeof(cc));
    for (int i = 0; i < n+4; i++) cc[i] = (i > 0 ? cc[i-1] : 0) + max(0, p[i] - (i > 0 ? p[i-1] : 0) - 1);
    for (int i = 0; i <= mex; i++) {
        int cnt = p[i] - (i > 0 ? p[i-1] : 0);
        // cout << i << ' ' << cnt << ' ';
        if (cnt > 0) dp[cnt-1]--;
        dp[min(n, p[mex] - (i > 0 ? p[i-1] : 0) + (i > 0 ? cc[i-1] : 0) + ccc)]++;
        // cout << min(n, p[mex] - (i > 0 ? p[i-1] : 0) + (i > 0 ? cc[i-1] : 0) + ccc)<< '\n';
    }
    for (int i = n-1; i >= 0; i--) dp[i] += dp[i+1];
    for (int i = 0; i <= n; i++) cout << dp[i] << ' '; cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}