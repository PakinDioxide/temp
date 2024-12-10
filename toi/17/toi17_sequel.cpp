#include <bits/stdc++.h>

using namespace std;

int a[100005], dp[100005][400];

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    int sq = sqrt(n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int m = 1; m <= sq; m++) for (int l = 1; l <= n; l++) dp[m][l] = dp[m][max(0, l-m)] + a[l];
    while (q--) {
        int l, m, r, ans = 0;
        scanf("%d %d %d", &l, &m, &r);
        if (m > sq) for (; l <= r; l += m) ans += a[l];
        else {
            r = l + ((r-l)/m)*m;
            l = max(0, l-m);
            ans = dp[m][r] - dp[m][l];
        }
        printf("%d ", ans);
    }
}