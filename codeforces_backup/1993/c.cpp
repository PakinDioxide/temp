#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n, k;
    scanf("%lld %lld", &n, &k);
    int a[n], mx = 0, c = 0;
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]), mx = max(mx, a[i]);
    c = mx;
    for (int i = 0; i < n; i++) {
        int mi = ((mx - a[i] + 2*k)/(2*k))*(2*k) + a[i], mxx = mi + k, mi2 = mi - 2*k, mxx2 = mi2 + k;
        // printf("(%lld %lld %lld %lld) ", mi, mxx, mi2, mxx2);
        if (mi2 >= a[i] && mi2 < mx + k && mxx2 > mx) c = max(c, mi2);
        else if (mi < mx + k && mxx > mx) c = max(c, mi);
        else {c = -1; break;}
    }
    for (int i = 0; i < n; i++) {
        int mi = ((mx - a[i] + 2*k)/(2*k))*(2*k) + a[i], mxx = mi + k, mi2 = mi - 2*k, mxx2 = mi2 + k;
        if (mi2 >= a[i] && mi2 < mx + k && mxx2 > mx && mxx2 > c) c = max(c, mi2);
        else if (mi < mx + k && mxx > mx && mxx > c) c = max(c, mi);
        else {c = -1; break;}
    }
    // printf("\n");
    printf("%lld\n", c);
}

int32_t main() {
    int t;
    scanf("%lld", &t);
    while (t--) solve();
}