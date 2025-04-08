/*
    author  : PakinDioxide
    created : 04/04/2025 14:41
    task    : 2019_Feb_S_2
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    ll dp[1005][1005];
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
    ll ans = 0;
    for (int i = 1; i <= 1001; i++) for (int j = 1; j <= 1001; j++) dp[i][j] += dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1], ans += (dp[i][j] == k);
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
*/