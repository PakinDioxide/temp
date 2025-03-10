#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n, m;
    scanf("%lld %lld", &n, &m);
    int a[n], mx = 0;
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    sort(a, a+n);
    vector <pair <int, int>> b;
    for (int e : a) {
        if (b.empty()  || b[b.size()-1].second != e) b.emplace_back(0, e);
        b[b.size()-1].first++;
    }
    for (int i = 0; i < b.size(); i++) {
        if (i < b.size() - 1 && b[i+1].second - b[i].second == 1) mx = max(mx, b[i].second * min(m/b[i].second, b[i].first) + b[i+1].second * min((m-b[i].second*min(m/b[i].second, b[i].first))/b[i+1].second, b[i+1].first));
        else mx = max(mx, b[i].second * min(m/b[i].second, b[i].first));
        // mx = max(mx, b[i].second * min(m/b[i].second, b[i].first));
        // if (i < b.size() - 1 && b[i+1].second - b[i].second == 1) {
        //     for (int j = 1; j <= min(m/b[i].second, b[i].first); j++) {
        //         mx = max(mx, b[i].second * j + b[i+1].second * min((m-b[i].second*j)/b[i+1].second, b[i+1].first));
        //     }
        // }
    }
    printf("%lld\n", mx);
}

int32_t main() {
    int t;
    scanf("%lld", &t);
    while (t--) solve();
}