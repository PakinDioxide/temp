#include <bits/stdc++.h>

using namespace std;

long long a[2005][2005], dp[2005][2005], dp2[2005][2005], n, m, k, ans = LLONG_MIN;

void solve() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + a[i][j];
            dp2[i][j] = dp2[i-1][j-1] + dp[i][j] - dp[i-1][j];
        }
    }
    for (int i = k; i <= n; i++) {
        for (int j = k; j <= m; j++) {
            ans = max(ans, dp2[i][j] - dp[i][j-k] - dp2[i-k][j-k] + dp[i-k][j-k]);
        }
    }
}

int main() {
    scanf("%lld %lld %lld", &n, &m, &k);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) scanf("%lld", &a[i][j]);
    solve();
    for (int i = 1; i <= n; i++) reverse(a[i]+1, a[i]+m+1);
    solve();
    printf("%lld", ans);
}

/*
explain :
dp2 ->
* * * * *
* * * * * *
* * * * * * *
* * * * * * * *
something like this
*/