#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n, ok = 1;
    scanf("%lld", &n);
    pair <int, int> a[n];
    for (int i = 0; i < n; i++) scanf("%lld %lld", &a[i].first, &a[i].second);
    int sx, sy, ex, ey;
    scanf("%lld %lld %lld %lld", &sx, &sy, &ex, &ey);
    int minc = INT_MAX, mint = (sx-ex)*(sx-ex) + (sy-ey)*(sy-ey);
    for (int i = 0; i < n; i++) {
        int p = (a[i].first-ex)*(a[i].first-ex) + (a[i].second-ey)*(a[i].second-ey);
        // printf("HI %lld %lld\n", p, mint);
        if (p <= mint) {ok = 0; break;}
    }
    if (ok) printf("YES\n");
    else printf("NO\n");
}

int32_t main() {
    int t;
    scanf("%lld", &t);
    while (t--) solve();
}