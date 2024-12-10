#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
    int t;
    scanf("%lld", &t);
    while (t--) {
        int n, mx = 0;
        scanf("%lld", &n);
        int a[n];
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
            if (a[i] > mx  && i < n-1) mx = a[i];
        }
        printf("%lld\n", mx + a[n-1]);
    }
}