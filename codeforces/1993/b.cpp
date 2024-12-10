#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n, cnt = 0;
    scanf("%lld", &n);
    int a[n];
    vector <int> o, e;
    int emx = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (a[i] & 1) o.push_back(a[i]), emx = max(emx, a[i]);
        else e.push_back(a[i]);
    }
    if (o.empty() || e.empty()) {printf("0\n"); return;}
    sort(e.begin(), e.end());
    int l = 0, r = e.size() - 1;
    while (l <= r) {
        if (e[l] < emx) emx += e[l], cnt++, l++;
        else emx += e[r--], cnt += 2;
    }
    printf("%d\n", cnt);
}

int32_t main() {
    int t;
    scanf("%lld", &t);
    while (t--) solve();
}