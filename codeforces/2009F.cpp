#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n, q, sum = 0;
    scanf("%lld %lld", &n, &q);
    int p[n+1], x;
    p[0] = 0;
    for (int i = 1; i <= n; i++) scanf("%lld", &x), p[i] = p[i-1] + x, sum += x;
    while (q--) {
        int l, r, ans = 0;
        scanf("%lld %lld", &l, &r);
        l--;
        ans += sum * (r/n - l/n);
        int x = (r/n)%n, y = (l/n)%n, xl = r%n, yl = l%n;
        ans += p[min(x+xl, n)] - p[x] - p[min(y+yl, n)] + p[y];
        xl = xl - n + x, yl = yl - n + y;
        if (xl > 0) ans += p[xl];
        if (yl > 0) ans -= p[yl];
        printf("%lld\n", ans);
    }
}

int32_t main() {
    int t;
    scanf("%lld", &t);
    while (t--) solve();
}