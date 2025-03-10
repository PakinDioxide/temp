#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n, k;
    scanf("%lld %lld", &n, &k);
    int cnt = 0;
    if (k == 1) {
        printf("%lld\n", n);
        return;
    }
    while (n > 0) {
        cnt += n % k;
        n /= k;
    }
    printf("%lld\n", cnt);
}

int32_t main() {
    int t;
    scanf("%lld", &t);
    while (t--) solve();
}