#include <stdio.h>
#include <math.h>

int main() {
    long long n, mod = 1e9+7, sum = 0;
    scanf("%lld", &n);
    long long cnt = 0, mx = 2*n - (n%2), k = 1;
    while (cnt < mx) {
        cnt++;
        sum = (sum + k) % mod;
        k = (k + n - (long long) ceil((float) cnt / 4)) % mod;
        if (cnt % 4 == 0) cnt += 4, mx += 4;
    }
    printf("%lld\n", sum);
}