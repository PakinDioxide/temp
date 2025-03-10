#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n, k;
    scanf("%lld %lld", &n, &k);
    long long a[n];
    priority_queue <pair <long long, long long>> q;
    for (long long i = 0; i < n; i++) scanf("%lld", &a[i]);
    for (long long i = 0; i < n; i++) {
        if (i < n-1 && a[i+1] < a[i]) q.emplace(a[i] - a[i+1], i);
        if (i > 0 && a[i-1] < a[i]) q.emplace(a[i] - a[i-1], i);
    }
    while (!q.empty() && k > 0) {
        auto [x, y] = q.top();
        q.pop();
        long long temp = a[y];
        if (y > 0) a[y] = min(a[y], a[y-1]);
        if (y < n-1) a[y] = min(a[y], a[y+1]);
        if (y > 0 && a[y-1] > a[y]) q.emplace(a[y] - a[y-1], y-1);
        if (y < n-1 && a[y+1] > a[y]) q.emplace(a[y] - a[y+1], y+1);
        if (a[y] != temp) k--;
    }
    long long ans = 0;
    for (long long i = 0; i < n; i++) ans += a[i];
    printf("%lld\n", ans);
}

int main() {
    long long q;
    scanf("%lld", &q);
    while (q--) solve();
}