#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;

int n, m, c[mxN], vis[mxN];
set <int> s[mxN];

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> c[i], vis[c[i]] = 1;
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        if (c[u] != c[v]) s[c[u]].emplace(c[v]), s[c[v]].emplace(c[u]);
    }
    int mx = -1, ans;
    for (int i = 1; i <= 1e5; i++) if (vis[i] && (int) s[i].size() > mx) mx = s[i].size(), ans = i;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    // int t; cin >> t;
    int t = 1;
    while (t--) solve();
}