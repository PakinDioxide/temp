#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
    int t;
    scanf("%lld", &t);
    while (t--) {
        int n, a, b;
        scanf("%lld %lld %lld", &n, &a, &b);
        int sum = a*n;
        b -= a;
        if (b > 0) sum += b*(b+1)/2;
        if (b > n) b -= n, sum -= b*(b+1)/2;
        printf("%lld\n", sum);
    }
}