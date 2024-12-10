#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n, m, ans = 0;
    scanf("%lld %lld", &n, &m);
    vector <vector <int>> a(n);
    int mex[n], smex[n], mx = 0;
    for (int o = 0; o < n; o++) {
        int l, x, f = 0;
        scanf("%lld", &l);
        map <int, int> cnt;
        for (int j = 0; j < l; j++) scanf("%lld", &x), a[o].push_back(x), cnt[x] = 1;
        for (int i = 1; i <= 1e9; i++) if (cnt[i] == 0) {
            if (f == 0) mex[o] = i;
            else smex[o] = i;
            if (f == 1) break;
            f = 1;
        }  
        mx = max(mx, smex[o]);
    }
    printf("MX :%lld\n", mx);
    int sum = 0;
    for (int i = 1; i <= m; i++) {
        if (i >= mx) {sum += i; continue;}
        else sum += mx;
    }
    printf("%lld\n", sum);
}

int32_t main() {
    int t;
    scanf("%lld", &t);
    while (t--) solve();
}