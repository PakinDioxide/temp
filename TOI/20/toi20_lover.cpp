#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, v, w;
    scanf("%d %d %d", &n, &v, &w);
    int e[n+1], o[n+1], a[n+1];
    e[0] = o[0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        e[i] = e[i-1], o[i] = o[i-1];
        if (a[i] & 1) o[i] += a[i];
        else e[i] += a[i];
    }
    int dp[n+1];
    dp[0] = 0;
    for (int i = 2; i <= n; i += 2) {
        dp[i] = INT_MAX;
        for (int j = 0; j < i; j += 2) {
            if (o[(i-j)/2 + j] - o[j] <= v && e[i] - e[j + (i-j)/2] <= w && dp[j] != -1) dp[i] = min(dp[i], dp[j] + 1);
        }
        dp[i] = dp[i] == INT_MAX ? -1 : dp[i];
    }
    printf("%d", dp[n]);
}