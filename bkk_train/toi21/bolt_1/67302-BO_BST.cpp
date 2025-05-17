#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    int l[n+1], r[n+1], a[n+1], vis[n+1], cnt = 0;
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) cin >> a[i] >> l[i] >> r[i];
    function <int(int, int, int)> dfs = [&] (int u, int mn, int mx) {
        if (vis[u] || !(mn <= a[u] && a[u] <= mx)) return 0;
        vis[u] = 1;
        cnt++;
        int ok = 1;
        if (l[u] != -1) {
            if (a[l[u]] > a[u]) return 0;
            ok = min(ok, dfs(l[u], mn, min(mx, a[u])));
        }
        if (r[u] != -1) {
            if (a[r[u]] < a[u]) return 0;
            ok = min(ok, dfs(r[u], max(mn, a[u]), mx));
        }
        return ok;
    };
    if (dfs(1, INT_MIN, INT_MAX) && cnt == n) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}