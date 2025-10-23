/*
    author  : 
    created : 11/07/2025 16:27
    task    : 660F
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    ll a[n+1], p[n+1], q[n+1], ans = 0;
    p[0] = q[0] = 0;
    deque <int> cht; cht.emplace_back(0);
    int sz = 1;
    auto calc = [&] (int idx, ll x) { return idx*x + idx*p[idx] - q[idx]; };
    auto m = [&] (int x, int y) { return (long double) (calc(x, 0) - calc(y, 0)) / (y - x); };
    for (int i = 1; i <= n; i++) {
        cin >> a[i], p[i] = p[i-1] + a[i], q[i] = q[i-1] + a[i]*i;
        while (sz > 1 && m(cht[sz-1], i) <= m(cht[sz-1], cht[sz-2])) cht.pop_back(), sz--; cht.emplace_back(i), sz++;
        int l = 0, r = sz-2, idx = sz-1;
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (m(cht[mid], cht[mid+1]) <= -p[i]) l = mid+1;
            else r = mid-1, idx = mid;
        }
        ans = max(ans, q[i] + calc(cht[idx], -p[i]));
    }
    cout << ans << '\n';
}