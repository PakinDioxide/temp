/*
    author  : PakinDioxide
    created : 22/03/2025 21:13
    task    : network
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    pair <ll, ll> a[n];
    for (auto &[x, y] : a) cin >> x >> y;
    int par[n+1];
    iota(par, par+n+1, 0);
    int m;
    cin >> m;
    function <int(int)> fi = [&] (int x) {
        if (par[x] != x) return par[x] = fi(par[x]);
        return x;
    };
    auto calc = [&] (int a, int b, int c, int d) {
        return abs(a-c) + abs(b-d);
    };
    int cnt = 0;
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if (fi(u) != fi(v)) par[fi(u)] = fi(v), cnt++;
    }
    priority_queue <tuple <ll, int, int>> q;
    for (int i = 0; i < n; i++) for (int j = i+1; j < n; j++) q.emplace(calc(a[i].first, a[i].second, a[j].first, a[j].second), i, j);
    ll ans = 0;
    while (!q.empty() && cnt < n-1) {
        auto [w, u, v] = q.top();
        q.pop();
        if (fi(u) != fi(v)) par[fi(u)] = fi(v), ans += w, cnt++;//, cout << u << ' ' << v << '\n';
    }
    cout << ans << '\n';
}