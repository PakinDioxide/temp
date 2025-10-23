/*
    author  : 
    created : 06/07/2025 21:54
    task    : 2124C
*/
#include <bits/stdc++.h>
#define ll long long
#define int ll

using namespace std;

void solve() {
    int n; cin >> n;
    int mx = 0, s = 0;
    int a[n]; for (auto &e : a) cin >> e, mx = max(mx, e), s += e;
    if (mx > s-mx) { cout << -1 << '\n'; return; }
    vector <vector <int>> ans;
    int ok = 0;
    while (1) {
        int sum = 0, mn = LLONG_MAX; for (auto &e : a) sum += e, mn = min(mn, e);
        vector <int> b(n);
        if (sum % 2 == 1) { cout << -1 << '\n'; return; }
        int cnt = 0, idx = 0;
        for (; idx < n; idx++) {
            cnt += a[idx];
            if (cnt * 2 >= sum) break;
        }
        if (cnt * 2 == sum) { for (int i = 0; i < n; i++) b[i] = a[i]; ans.emplace_back(b); ok = 1; break; }
        int sl = 0, sr = 0;
        while (sl == 0 || sr == 0) {
            for (int i = 0; i < n; i++) {
                b[i] = a[i] - mn;
                if (i <= idx) sl += b[i];
                else sr += b[i];
            }
            mn--;
        }
        int cc = abs(sl - sr);
        if (sl < sr) {
            int idx = 0;
            while (cc) {
                if (b[idx] >= cc) b[idx] -= cc, cc = 0;
                else cc -= b[idx], b[idx] = 0;
                idx++;
            }
        } else {
            int idx = n-1;
            while (cc) {
                if (b[idx] >= cc) b[idx] -= cc, cc = 0;
                else cc -= b[idx], b[idx] = 0;
                idx--;
            }
        }
        ans.emplace_back(b);
        for (int i = 0; i < n; i++) a[i] -= b[i];
    }
    cout << ans.size() << '\n';
    for (auto &E : ans) {
        for (auto &e : E) cout << e << ' ';
        cout << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}