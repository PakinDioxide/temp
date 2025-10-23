/*
    author  : 
    created : 05/07/2025 22:23
    task    : 2119D
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll n, m; cin >> n >> m;
    int cnt = 0;
    for (int i = 0; i <= 1; i++) for (int j = 0; j <= 2; j++) for (int k = 0; k <= 0; k++) for (int l = 0; l <= 0; l++) {
        int a[5] = {0, i, j, k, l};
        int mk[5] = {0, 0, 0, 0, 0};
        for (int i = 1; i <= n; i++) cout << a[i] << ' '; cout << '\n';
        int ans = 1;
        for (int ii = 1; ii <= n; ii++) {
            if (a[ii] == 0) {mk[ii] = 1; continue;}
            int zr = 0, mm = ii;
            for (int jj = ii-1; jj >= a[ii]; jj--) zr += !a[jj], mm = (a[jj] == 0 ? jj : mm);
            ans *= n-mm+zr;
        }
        // cout << ans << '\n';
        cnt += ans;
    }
    cout << cnt << '\n';
    // ll dp[n+1][n+1];
    // dp[0][0] = 1;
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 0; j < i; j++) {
    //         dp[i][j] = dp[i-1][j] + 
    //     }
    // }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}

/*
if before i, there isn't any zero, then we have to remove i only
else we can remove number of zeros in the interval + 1 ways
*/