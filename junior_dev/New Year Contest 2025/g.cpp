// PakinDioxide
#include <bits/stdc++.h>
#define int long long

using namespace std;

int par[100005], co[100005];

int fi(int u) {
    if (par[u] != u) return par[u] = fi(par[u]);
    return u;
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k; k--;
    for (int i = 1; i <= n; i++) par[i] = i, co[i] = 1;
    priority_queue <tuple <int, int, int>> q;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        q.emplace(w, u, v);
    }
    int cnt = 0, mnk = n-1, mx = LLONG_MAX;
    while (!q.empty() && mnk > k) {
        auto [w, u, v] = q.top();
        q.pop();
        if (fi(u) == fi(v)) continue;
        // co[fi(v)] += co[fi(u)];
        par[fi(u)] = fi(v);
        cnt = max(cnt, co[fi(v)]);
        mx = min(mx, w);
        mnk--;
    }
    if (mnk <= k) cout << (mx == INT_MAX ? 0 : mx);
    else cout << "DEADLY SIN";
}