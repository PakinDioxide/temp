#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    int cnt[n+1];
    bitset <505> a[n+1], b[n+1];
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        cnt[i] = 0;
        for (int j = 0; j < n; j++) a[i][j+1] = (s[j] == '1'), cnt[i] += (s[j] == '1');
    }
    for (int i = 1; i <= n; i++) if (a[i][i] == 0) { cout << "NO\n"; return; }
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (a[i][j] && a[j][i] && i != j) { cout << "NO\n"; return; }
    vector <int> adj[n+1];
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
        if (a[i][j] && i != j) adj[i].emplace_back(j);
    }
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
        if (a[i][j] && ((a[i] & a[j]) ^ a[j]) != 0) { cout << "NO\n"; return; }
    }
        for (int i = 1; i <= n; i++) {
        int vis[n+1]; memset(vis, 0, sizeof(vis));
        queue <int> q;
        q.emplace(i);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto v : adj[u]) {
                if (v == i) { cout << "NO\n"; return; }
                if (!vis[v]) vis[v] = 1, q.emplace(v);
            }
        }
    }
    int par[n+1]; iota(par, par+n+1, 0);
    function <int(int)> fi = [&] (int x) {
        if (x == par[x]) return x;
        return par[x] = fi(par[x]);
    };
    for (int u = 1; u <= n; u++) {
        for (auto v : adj[u]) if (fi(u) != fi(v)) {
            par[fi(u)] = fi(v);
        }
    }
    for (int i = 1; i < n; i++) if (fi(i) != fi(i+1)) { cout << "NO\n"; return; }
    for (int i = 1; i <= n; i++) b[i] |= a[i];
    vector <pair <int, int>> E;
    for (int i = 1; i <= n; i++) {
        vector <pair <int, int>> mx;
        for (int j = 1; j <= n; j++) if (i != j) mx.emplace_back(cnt[j], j);
        sort(mx.begin(), mx.end());
        while (mx.size()) {
            if (!b[i][mx.back().second]) { mx.pop_back(); continue; }
            E.emplace_back(i, mx.back().second);
            b[i] ^= a[mx.back().second];
            mx.pop_back();
        }
    }
    int vis[n+1]; memset(vis, 0, sizeof(vis));
    for (auto &[x, y] : E) vis[x] = 1, vis[y] = 1;
    int c = 0;
    for (auto &e : vis) c += e;
    if ((int) E.size() != n-1 || c != n) { cout << "NO\n"; return; }
    cout << "YES\n";
    for (auto &[x, y] : E) cout << x << ' ' << y << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}


