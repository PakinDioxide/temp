#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n, k;
    scanf("%lld %lld", &n, &k);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    sort(a, a+n);
    int l = 1, r = n, ans = 0;
    while (l <= r) {
        int m = (l+r)/2, c = 0;
        for (int i = n-m; i < n; i++) {
            c += a[i] - a[max(n-m-1, 0LL)];
        }
        if (c <= k) {
            ans = m;
            l = m+1;
        } else r = m-1;
    }
    printf("%d\n", ans);
}

int32_t main() {
    int t;
    scanf("%lld", &t);
    while (t--) solve();
}