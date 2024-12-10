#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n, q;
    scanf("%lld %lld", &n, &q);
    int a[n], cnt[n], cnt2[n];
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]), cnt[i] = i < n-1 ? (i+1) * (n-i-1) : 0, cnt2[i] = (i+1) * (n-i) - 1;
    map <int, int> dp;
    for (int i = 0; i < n; i++) {
        dp[cnt2[i]]++;
        if (i < n-1) dp[cnt[i]] += a[i+1] - a[i] - 1;
    }
    while (q--) {
        int x, c = 0;
        scanf("%lld", &x);
        printf("%lld ", dp[x]);
    }
    printf("\n");
}

int32_t main() {
    int t;
    scanf("%lld", &t);
    while (t--) solve();
}