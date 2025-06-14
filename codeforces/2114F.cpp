/*
    author  : PakinDioxide
    created : 26/05/2025 22:11
    task    : 2114F
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int x, y, k; cin >> x >> y >> k;
    map <int, int> vx, vy;
    for (int i = 2; i <= x; i++) while (x % i == 0) x /= i, vx[i]++;
    for (int i = 2; i <= y; i++) while (y % i == 0) y /= i, vy[i]++;
    multiset <int> rm, ps;
    for (auto &[x, y] : vx) if (y - vy[x] > 0) for (int i = 0; i < y - vy[x]; i++) rm.emplace(x);
    for (auto &[x, y] : vy) if (y - vx[x] > 0) for (int i = 0; i < y - vx[x]; i++) ps.emplace(x);
    if ((!rm.empty() && *prev(rm.end()) > k) || (!ps.empty() && *prev(ps.end()) > k)) { cout << -1 << '\n'; return; }
    int ans = 0;
    while (!rm.empty()) {
        ll s = k;
        auto it = rm.upper_bound(s);
        while (it != rm.begin()) it = prev(it), s /= *it, rm.erase(it), it = rm.upper_bound(s);
        ans++;
    }
    while (!ps.empty()) {
        ll s = k;
        auto it = ps.upper_bound(s);
        while (it != ps.begin()) it = prev(it), s /= *it, ps.erase(it), it = ps.upper_bound(s);
        ans++;
    }
    cout << ans << '\n';
    // cout << "RM ";
    // for (auto &e : rm) cout << e << ' '; 
    // cout << '\n' << "PS ";
    // for (auto &e : ps) cout << e << ' '; 
    // cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}