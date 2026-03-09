#include <bits/stdc++.h>
#define ll long long
#define int ll

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    int a[n]; for (auto &e : a) cin >> e;
    sort(a, a+n);
    unordered_map <int, int> vis, vv;
    for (auto &e : a) vis[e] = 1;
    if (k/a[0] > n) { cout << -1 << '\n'; return; }
    vector <int> b;
    for (auto &e : a) if (!vv[e]) {
        for (int x = e; x <= k; x += e) {
            if (!vis[x]) { cout << -1 << '\n'; return; }
            vv[x] = 1;
        }
        b.emplace_back(e);
    }
    cout << b.size() << '\n';
    for (auto &e : b) cout << e << ' '; cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

/*
k/x <= n
k/n <= x
*/