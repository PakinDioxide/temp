#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, ans = 0;
    cin >> n;
    int vis[n+1];
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++) {
        int u;
        cin >> u;
        if (vis[u]) ans++;
        vis[u] = 1;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}