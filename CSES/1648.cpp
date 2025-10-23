#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, fw[200001], a[200001];

int32_t main() {
    int n, q;
    scanf("%lld %lld", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        for (int j = i; j <= n; j += (j & (-j))) fw[j] += a[i];
    }
    while (q--) {
        int x, p, q;
        scanf("%lld %lld %lld", &x, &p, &q);
        if (x == 1) {
            for (int j = p; j <= n; j += (j & (-j))) fw[j] += q - a[p];
            a[p] = q;
        } else {
            int sum = 0;
            for (int j = q; j > 0; j -= (j & (-j))) sum += fw[j];
            for (int j = p-1; j > 0; j -= (j & (-j))) sum -= fw[j];
            printf("%lld\n", sum);
        }
    }
}