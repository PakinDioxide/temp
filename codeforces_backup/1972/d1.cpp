#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n, m;
    scanf("%lld %lld", &n, &m);
    long long ans = 0;
    for (int b = 1; b <= m; b++) {
        if (b*b-b-1 > n+b) break;
        ans += (n+b)/(b*b) + max(0, b*b-b-1)/(b*b);
    }
    printf("%lld\n", ans-1);
}

int main() {
    int q;
    scanf("%d", &q);
    while (q--) solve();
}
