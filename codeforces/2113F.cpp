/*
    author  : 
    created : 15/06/2025 17:29
    task    : 2113F
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n; int a[n], b[n], p[2*n+5], q[2*n+5];
    memset(p, 0, sizeof(p)), memset(q, 0, sizeof(q));
    for (auto &e : a) cin >> e; for (auto &e : b) cin >> e;
    vector <tuple <int, int, int>> v(n), v2(n);
    for (int i = 0; i < n; i++) v[i] = make_tuple(a[i], b[i], i);
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        auto [x, y, idx] = v[i];
        if (!p[y] && y < x) swap(x, y);
        else if (p[x] && !p[y]) swap(x, y);
        else if (p[x] && p[y] && !q[x]) swap(x, y);
        p[x]++, q[y]++;
        a[idx] = x, b[idx] = y;
    }
    for (int i = 0; i < n; i++) {
        if (!q[a[i]] && q[b[i]] > 1 && !p[b[i]]) swap(a[i], b[i]), p[a[i]]++, p[b[i]]--, q[b[i]]++, q[a[i]]--;
    }
    // memset(p, 0, sizeof(p)), memset(q, 0, sizeof(q));
    // for (int i = 0; i < n; i++) {
    //     p[a[i]] = q[b[i]] = 1;
    // }
    int cnt = 0;
    for (auto &e : p) cnt += (e > 0); for (auto &e : q) cnt += (e > 0);
    cout << cnt << '\n';
    for (auto &e : a) cout << e << ' '; cout << '\n';
    for (auto &e : b) cout << e << ' '; cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}