#include <bits/stdc++.h>
#define ll long long
#define sh short

using namespace std;

sh n, m, k, x, y, a[2500][2500], dp[2][2500][20005], ans[20005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> k;
    for (sh i = 0; i < n; i++) for (sh j = 0; j < m; j++) a[i][j] = k;
    for (sh i = 0; i < k; i++) cin >> x >> y, x--, y--, a[x][y] = i;
    for (sh i = 0; i < n; i++) for (sh j = 0; j < m; j++) for (sh ii = 0; ii < k; ii++) {
        if (ii >= a[i][j]) dp[i&1][j][ii] = 0;
        else if (i == 0 || j == 0) dp[i&1][j][ii] = 1;
        else dp[i&1][j][ii] = min({dp[!(i&1)][j][ii], dp[i&1][j-1][ii], dp[!(i&1)][j-1][ii]}) + 1;
        ans[ii] = max(ans[ii], dp[i&1][j][ii]);
    }
    for (int i = 0; i < k; i++) cout << ans[i] << '\n';
}
