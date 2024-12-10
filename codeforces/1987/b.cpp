#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
    int t;
    scanf("%lld", &t);
    while (t--) {
        int n;
        scanf("%lld", &n);
        vector <int> c(n);
        for (int i = 0; i < n; i++) scanf("%lld", &c[i]);
        vector <int> v;
        for (int i = 1; i < n; i++) if (c[i] < c[i-1]) v.push_back(c[i-1] - c[i]), c[i] = c[i-1];
        sort(v.begin(), v.end());
        if (v.empty()) {printf("0\n"); continue;}
        int cnt = 0, m = 0, idx = 0, r = 0;
        while (idx != v.size()) {
            cnt += (v.size() - r + 1) * (v[idx] - m);
            m = v[idx];
            idx = upper_bound(v.begin(), v.end(), v[idx]) - v.begin();
            r = idx;
        }
        printf("%lld\n", cnt);
    }
}