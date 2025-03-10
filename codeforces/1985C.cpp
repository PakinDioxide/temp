#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
    int q;
    scanf("%lld", &q);
    while (q--) {
        int n;
        scanf("%lld", &n);
        int a[n+1], p[n+1], mx = INT_MIN, c = 0;
        a[0] = p[0] = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
            p[i] = p[i-1] + a[i];
            mx = max(a[i], mx);
            if (p[i] - mx == mx) c++;
        }
        printf("%lld\n", c);
    }
}