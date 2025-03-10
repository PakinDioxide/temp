#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
    int t;
    scanf("%lld", &t);
    while (t--) {
        int n, k;
        scanf("%lld %lld", &n, &k);
        if (k & 1LL) printf("No\n");
        else {
            // printf("Yes\n");
            int id = 0, idx = n-1, a[n];
            for (int i = 0; i < n; i++) a[i] = i+1;
            k /= 2;
            while (k > 0 && idx > id) {
                if (k > idx - id) {
                    k -= (idx - id);
                    swap(a[idx], a[id]);
                } else {
                    swap(a[idx], a[idx-k]);
                    k = 0;
                }
                id++, idx--;
            }
            if (k > 0) {printf("No\n"); continue;}
            printf("Yes\n");
            for (int i = 0; i < n; i++) printf("%lld ", a[i]);
            printf("\n");
        }
    }
}