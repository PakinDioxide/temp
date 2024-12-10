#include <stdio.h>
#include <string.h>

void solve() {
    char s[1000005];
    long long m, x;
    scanf("%lld %lld", &m, &x);
    while (--m) {
        scanf("%s", &s);
        long long n = strlen(s), ans = 0;
        for (long long i = 0; i < n; i++) {
            ans = 10 * ans + (s[i] - '0');
            ans %= x;
        }
        printf("%lld\n", ans);
    }
}

int main() {
    long long q;
    scanf("%lld", &q);
    while (q--) solve();
}