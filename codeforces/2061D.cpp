/*
    author  : 
    created : 01/08/2025 22:06
    task    : 2061D
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    int a[n], b[m], sa = 0, sb = 0;
    for (auto &e : a) cin >> e, sa += e;
    for (auto &e : b) cin >> e, sb += e;
    if (sa != sb) { cout << "No\n"; return; }
    unordered_map <int, int> c, rec;
    for (auto &e : a) c[e]++;
    for (auto &e : b) rec[-e]++;
    for (auto &e : a) { int k = min(c[e], rec[-e]); c[e] -= k, rec[-e] -= k; }
    set <int> s, s2;
    for (auto &[e, y] : rec) if (y > 0) s.emplace(e);
    for (auto &[e, y] : c) if (y > 0) s2.emplace(-e);
    auto it = s.begin();
    int ok = 1;
    while (it != s.end()) {
        int x = *it; int y = rec[*it];
        if (!s2.empty() && x > *s2.begin()) { ok = 0; break; }
        int y2 = y - min(c[-x], y);
        if (c[-x]) s2.erase(s2.begin());
        c[-x] -= min(c[-x], y);
        if (c[-x] > 0) { ok = 0; break; }
        rec[-(-x/2)] += y2;
        rec[-ceil(-x/2.0)] += y2;
        if (y2 > 0) s.emplace(-(-x/2)), s.emplace(-ceil(-x/2.0));
        it++;
    }
    ok = min(ok, (int) (!rec[0]));
    if (ok) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}