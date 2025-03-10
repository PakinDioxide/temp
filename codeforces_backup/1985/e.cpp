#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
    int q;
    scanf("%lld", &q);
    while (q--) {
        int x[3], k;
        scanf("%lld %lld %lld %lld", &x[0], &x[1], &x[2], &k);
        sort(x, x+3);
        int y[3];
        for (y[0] = cbrt(k); y[0] > x[2] || k % y[0] > 0; y[0]--);
        k /= y[0];
        for (y[1] = sqrt(k); y[1] > x[1] || k % y[1] > 0; y[1]--);
        y[2] = (k /= y[1]);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (max(0LL, x[i] - y[i] + 1) * max(0LL, x[j] - y[j] + 1) < max(0LL, x[i] - y[j] + 1) * max(0LL, x[j] - y[i] + 1)) swap(y[i], y[j]);
            }
        }
        int ans = max(0LL, x[0] - y[0] + 1) * max(0LL, x[1] - y[1] + 1) * max(0LL, x[2] - y[2] + 1);
        printf("%lld\n", ans);
    }
}