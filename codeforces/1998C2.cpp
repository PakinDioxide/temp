#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n, k, mx = 0;
    scanf("%lld %lld", &n, &k);
    pair <int, int> a[n];
    for (int i = 0; i < n; i++) scanf("%lld", &a[i].first);
    for (int i = 0; i < n; i++) {scanf("%lld", &a[i].second); if (a[i].second) mx = max(mx, a[i].first);}
    sort(a, a+n);
    if (mx > 0) printf("%lld\n", mx + a[((n+1)/2) - 1].first + k);
    else printf("%lld\n", a[((n+1)/2) - 1].first + a[n-1].first);
}

int32_t main() {
    int t;
    scanf("%lld", &t);
    while (t--) solve();
}