/*
    author  : PakinDioxide
    created : 04/04/2025 14:41
    task    : 2009_Feb_G_3
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);
    ll n, k;
    cin >> n >> k;
    ll dp[210][210];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1++, y1++;
        dp[x1][y1]++;
        dp[x2+1][y1]--;
        dp[x1][y2+1]--;
        dp[x2+1][y2+1]++;
    }
    ll cnt = 0, p[210][210];
    for (int i = 1; i <= 200; i++) for (int j = 1; j <= 200; j++) dp[i][j] += dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1], cnt += (dp[i][j] == k), p[i][j] = (dp[i][j] == k ? -1 : dp[i][j] == k-1 ? 1 : 0);
    // for (int i = 1; i <= 10; i++) {for (int j = 1; j <= 10; j++) cout << p[i][j] - p[i-1][j] - p[i][j-1] + p[i-1][j-1] << ' '; cout << '\n';}
    // for (int i = 1; i <= 10; i++) {for (int j = 1; j <= 10; j++) cout << dp[i][j] << ' '; cout << '\n';}
    ll ans = cnt;
    // seperate it verticaly
    for (int m = 1; m <= 200; m++) {
        ll k1 = 0, k2 = 0;
        for (int i = 1; i <= 200; i++) {
            ll x[210];
            memset(x, 0, sizeof(x));
            for (int j = 1; j <= m; j++) {
                ll sum = 0;
                for (int k = 0; i-k > 0; k++) sum += p[i-k][j], x[k] = max(sum, x[k] + sum), k1 = max(k1, x[k]);
            }
            memset(x, 0, sizeof(x));
            for (int j = m+1; j <= 200; j++) {
                ll sum = 0;
                for (int k = 0; i-k > 0; k++) sum += p[i-k][j], x[k] = max(sum, x[k] + sum), k2 = max(k2, x[k]);
            }
        }
        ans = max(ans, k1+k2+cnt);
    }
    // seperate it horizontaly
    for (int m = 1; m <= 200; m++) {
        ll k1 = 0, k2 = 0;
        for (int i = 1; i <= m; i++) {
            ll x[210];
            memset(x, 0, sizeof(x));
            for (int j = 1; j <= 200; j++) {
                ll sum = 0;
                for (int k = 0; i-k > 0; k++) sum += p[i-k][j], x[k] = max(sum, x[k] + sum), k1 = max(k1, x[k]);
            }
        }
        for (int i = m+1; i <= 200; i++) {
            ll x[210];
            memset(x, 0, sizeof(x));
            for (int j = 1; j <= 200; j++) {
                ll sum = 0;
                for (int k = 0; i-k > m; k++) sum += p[i-k][j], x[k] = max(sum, x[k] + sum), k2 = max(k2, x[k]);
            }
        }
        ans = max(ans, k1+k2+cnt);
    }
    cout << ans << '\n';
}

/*
we can do a prefix sum 2d array that a_i_j will equal to the sum from 0, 0 to i, j

when we add the time complexity will be o(n):
    let x1, y1 be the left top corner, x2, y2 be the right bottom corner
    dp[x1][y1]++;
    dp[x2+1][y1]--;
    dp[x1][y2+1]--;
    dp[x2+1][y2+1]++;

what if we do maximum submatrix

we can devide the square into 2 parts
1. vertical
2. horizontal

because it doesn't overlap each other

total time complexity : o(n^4)
*/