#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int a = 0, b, c, d;
    scanf("%lld %lld %lld", &b, &c, &d);
    int mx = c + d;
    if (mx < b) printf("-1\n");
    else printf("%lld\n", b|c);
}

int32_t main() {
    int t;
    scanf("%lld", &t);
    while (t--) solve();
}