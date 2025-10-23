#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    multiset <pair <int, int>> ms;
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        ms.emplace(-x, i+1);
    }
    int r = -1, N = n;
    vector <int> v;
    while (N--) {
        if (ms.empty()) { cout << -1 << '\n'; return; }
        if ((*ms.begin()).second == r) {
            if (ms.size() == 1) { cout << -1 << '\n'; return; }
            auto [x, y] = *next(ms.begin());
            ms.erase(next(ms.begin()));
            r = y; v.emplace_back(y);
            x++;
            if (x < 0) ms.emplace(x, y);
        } else {
            auto [x, y] = *ms.begin();
            ms.erase(ms.begin());
            r = y; v.emplace_back(y);
            x++;
            if (x < 0) ms.emplace(x, y);
        }
    }
    if (v[0] == v[n-1]) {
        int ok = 0;
        for (auto &[x, y] : ms) if (y != v[n-2] && y != v[0]) { v[n-1] = y, ok = 1; break; }
        if (!ok) {
            for (int i = 2; i < n-1; i++) if (v[i] != v[n-1] && v[i-1] != v[n-1] && (v[i+1] != v[n-1] || i == n-2) && (v[i] != v[n-2] || i == n-2)) { swap(v[n-1], v[i]); ok = 1; break; }
        }
        if (!ok) { cout << -1 << '\n'; return; }
    }
    for (auto &e : v) cout << e << ' '; cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    // int t; cin >> t;
    int t = 1;
    while (t--) solve();
}