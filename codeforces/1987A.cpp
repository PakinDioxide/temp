#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
    int t;
    scanf("%lld", &t);
    while (t--) {
        int n, k;
        scanf("%lld %lld", &n, &k);
        printf("%lld\n", (n-1)*k+1);
    }
}