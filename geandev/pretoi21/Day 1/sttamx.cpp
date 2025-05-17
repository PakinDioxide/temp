#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5, mxK = 505;

ll n, k, a[mxN], p[mxN], mn = LLONG_MAX, dp[mxN], vis[mxN];

// void solve(int idx, ll st, ll c, ll mx, ll s, ll s2) {
//     if (idx > n) {mn = min(mn, s+(mx*c-s2)); return;}
//     if (c > k || st) solve(idx+1, 0, 1, a[idx], s+(mx*c-s2), a[idx]);
//     solve(idx+1, st, c+1, max(mx, a[idx]), s, s2+a[idx]);
// }

// ll solve(ll idx, ll st) {
//     if (vis[idx]) return dp[idx];
//     vis[idx] = 1;
//     if (idx > n) return dp[idx] = 0;
//     ll mn = LLONG_MAX, mx = 0;
//     for (int i = idx; i <= n; i++) {
//         mx = max(mx, a[i]);
//         ll K = 0;
//         if (i-idx+1 > k || st || i == n) mn = min(mn, K = (mx*(i-idx+1)-(p[i]-p[idx-1]) + solve(i+1, 0)));
//         // cout << "SOV " << idx << ' ' << i << ' ' << K << '\n';
//     }
//     // cout << idx << ' ' << mn << '\n';
//     return dp[idx] = mn;
// }

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    p[0] = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], p[i] = a[i] + p[i-1];
    // solve(1, 1, 0, 0, 0, 0);
    // cout << mn << '\n';

    // cout << solve(1, 1) << '\n';
    ll mx2 = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = mx2*(i-1)-p[i-1];
        mx2 = max(mx2, a[i]);
        if (i <= k) continue;
        ll mx = 0;
        for (int c = 0; c <= k; c++) mx = max(mx, a[i-c]);
        dp[i] = min(dp[i], dp[i-k-1] + (k+1)*(mx)-(p[i]-p[i-k-1]));
    }
    mx2 = 0;
    ll mn = dp[n];
    for (int i = 1; i <= n; i++) cout << dp[i] << ' ';
    cout << '\n';
    for (int i = n; i >= 1; i--) mx2 = max(mx2, a[i]), mn = min(mn, dp[i-1] + (n-i+1)*mx2-(p[n]-p[i-1]));
    cout << mn << '\n';

    // SUB1
    // cout << 0 << '\n';

    // BRUTEFORCE - O(n^2)
    // pair <ll, ll> dp[n+1][k+1];
    // for (int i = 0; i <= k; i++) dp[1][i] = make_pair(0, a[1]);
    // for (int i = 2; i <= n; i++) for (int j = 0; j <= k; j++) {
    //     if (j == 0) dp[i][j] = make_pair(dp[i-1][k].first + (k*dp[i-1][k].second-(p[i-1]-(i-k>=0?p[i-k]:0))), a[i]);
    //     else dp[i][j] = make_pair(dp[i-1][j-1].first, max(dp[i-1][j-1].second, a[i]));
    // }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 0; j <= k; j++) cout << "(" << dp[i][j].first << ' ' << dp[i][j].second << ") ";
    //     cout << '\n';
    // }
    // ll mn = LLONG_MAX;
    // for (int i = 0; i <= k; i++) mn = min(mn, dp[n][i].first+(i*dp[n][i].second-(p[n]-(n-i>=0?p[n-i]:0))));
    // cout << mn << '\n';

    // ll dp[n+1], mx = 0;
    // dp[0] = 0;
    // for (int i = 1; i <= n; i++) {
    //     dp[i] = mx*(i-1)-p[i-1];
    //     mx = max(mx, a[i]);
    //     if (i <= k) continue;
    //     ll mmx = 0;
    //     for (int j = i; j >= i-k; j--) mmx = max(mmx, a[j]);
    //     for (int j = i-k-1; j >= 0; j--) {
    //         dp[i] = min(dp[i], dp[j]+mmx*(i-j)-(p[i]-p[j]));
    //         mmx = max(mmx, a[j]);
    //     }
    //     cout << dp[i] << ' ';
    // }
    // cout << dp[n] << '\n';
}

/*
Do O(nklog(sth?))
*/