#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    pair <int, int> a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i].first);
    for (int i = 0; i < n; i++) scanf("%d", &a[i].second);
    sort(a, a+n);
    int l = 0, r = 2e9, mid = ((n+1)/2) - 1, mx = 0;
    while (l <= r) {
        // printf("L R %d %d\n", l, r);
        int mi = l + (r-l)/2, cnt = 0, sum = 0;
        for (int i = n-1; i > 0; i--) {
            if (a[i].second == 0) {
                if (a[i].first >= mi) cnt++;
                continue;
            }
            cnt++;
            sum += max(0, mi - a[i].first);
            if (cnt >= mid || sum > k) break;
        }
        if (cnt < mid || sum > k) r = mi - 1;
        else mx = max(mx, mi), l = mi + 1, printf("MI %d %d\n", mi, cnt);
    }
    int cnt = 0, used = 0;
    for (int i = n; i > 0; i--) {
        if (k - used >= max(0, mx - a[i].first)) {
            used += max(0, mx - a[i].first);
            a[i].first = mx;
        } else {
            a[i].first += k-used;
            break;
        }
    }
    sort(a, a+n);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\nMXf : %d %d\n", mx, mid);
    printf("%lld\n", (long long) a[mid].first + mx);
    // for (int i = n; i > 0; i--) {
    //     if (a[i].second == 0) continue;
    //     cnt++;
    //     sum += max(0, mi - a[i]);
    // }
    // mid = ((n)/2) - 1;
    // for (int i = 0; i < n; i++) {
    //     if (i > mid) mx = max(mx, a[i] + a[mid]);
    //     else mx = max(mx, a[i] + a[mid-1]);
    // }
    // printf("%d\n", mx);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
}