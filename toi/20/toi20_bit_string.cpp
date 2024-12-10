#include <bits/stdc++.h>

using namespace std;

int n, q, c[1LL << 20], vis[1LL << 20], dp[1LL << 20];

int solve(int x) {
    if (vis[x]) return dp[x];
    vis[x] = 1;
    dp[x] = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (x & (1 << i)) dp[x] = max(dp[x], solve(x ^ (1 << i)));
        if (i < n-1 && (x & (1 << i)) && (x & (1 << (i + 1)))) dp[x] = max(dp[x], solve((x ^ (1 << i)) ^ (1 << (i+1))));
    }
    return dp[x] = dp[x] + c[x];
}

int32_t main() {
    scanf("%d %d", &n, &q);
    for (int i = 0; i < (1 << n); i++) {
        char s[n];
        scanf("%s", &s);
        int num = 0;
        for (int j = 0; j < n; j++) {
            if (s[j] == '1') num |= (1 << (n - j - 1));
        }
        scanf("%d", &c[num]);
    }
    vis[0] = 1, dp[0] = c[0];
    while (q--) {
        char s[n];
        scanf("%s", &s);
        int num = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') num |= (1 << (n - i - 1));
        }
        printf("%d\n", solve(num));
    }
}