#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, q, fen[200005], a[200005];

int32_t main() {
    scanf("%lld %lld", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        int idx = i;
        for (; idx <= n; idx += (idx & (-idx))) fen[idx] += a[i] - a[i-1];
    }
    while (q--) {
        int t;
        scanf("%lld", &t);
        if (t == 1) {
            int a, b, c;
            scanf("%lld %lld %lld", &a, &b, &c);
            for (; a <= n; a += (a & (-a))) fen[a] += c;
            b++;
            for (; b <= n; b += (b & (-b))) fen[b] -= c;
        } else {
            int k;
            scanf("%lld", &k);
            int sum = 0;
            for (int idx = k; idx > 0; idx -= (idx & (-idx))) sum += fen[idx];
            printf("%lld\n", sum);
        }
    }
}