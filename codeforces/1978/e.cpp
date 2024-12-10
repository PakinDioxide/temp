#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
    int t;
    scanf("%lld", &t);
    while (t--) {
        int n;
        scanf("%lld", &n);
        char a[n+1], b[n+1];
        int p[n+1];
        p[0] = 0;
        scanf("%s %s", &a, &b);
        for (int i = 0; i < n-2; i++) if (a[i] == a[i+2] && a[i] == '0') b[i+1] = '1';
        for (int i = 0; i < n; i++) {
            if (i < n-2 && b[i] == b[i+2] && b[i] == '1') a[i+1] = '1';
            p[i+1] = p[i] + (a[i] == '1');
        }
        int q;
        scanf("%lld", &q);
        while (q--) {
            int l, r;
            scanf("%lld %lld", &l, &r);
            printf(" %lld\n", p[r] - p[l-1]);
        }
    }
}