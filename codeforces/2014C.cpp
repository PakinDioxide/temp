#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n;
    scanf("%lld", &n);
    int a[n], sum = 0, mx = 0, idx = 0;
    for (int i = 0; i < n; i++) {scanf("%lld", &a[i]), sum += a[i]; if (a[i] > mx) {mx = a[i]; idx = i;}}
    int l = 0, r = INT_MAX, ans = 0;
    while (l <= r) {
        // printf("%lld %lld\n", l, r);
        if (l < 0 || r < 0) {ans = -1; break;}
        int mid = (l+r)/2;
        int c = 0, ss = ceil(((float) mid + sum)/n/2);
        a[idx] += mid;  
        for (int i = 0; i < n; i++) if (a[i] < ss) c++;
        if (c > n/2) {
            // printf("MM %lld %lld\n", mid, c);
            ans = mid;
            r = mid-1;
        } else l = mid+1;
        a[idx] -= mid;
    }
    printf("%lld\n", r == INT_MAX ? -(1LL) : ans);
}

int32_t main() {
    int t;
    scanf("%lld", &t);
    while (t--) solve();
}