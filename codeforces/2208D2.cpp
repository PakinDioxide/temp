#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    int cnt[n+1];
    bitset <8005> a[n+1], b[n+1];
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
    // O(N^3)
    /*
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
        if (a[i][j] && ((a[i] & a[j]) ^ a[j]) != 0) { cout << "NO\n"; return; }
    }
    */
    int V[n+1]; memset(V, 0, sizeof(V));

    for (int i = 1; i <= n; i++) b[i] |= a[i];
    int ok = 1;
    vector <pair <int, int>> mx[n+1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) if (i != j && a[i][j]) mx[i].emplace_back(cnt[j], j);
        sort(mx[i].begin(), mx[i].end());
    }
    function <void(int)> idk = [&] (int i) {
        if (V[i] || !ok) return;
        V[i] = 1;
        for (int k = (int) mx[i].size() - 1; k >= 0; k--) {
            if (!b[i][mx[i][k].second]) { continue; }
            for (auto &e : adj[mx[i][k].second]) {
                if (a[i][e] == 0) { ok = 0; return; }
                b[i][e] = 0;
                idk(e);
            }
        }
    };
    for (int i = 1; i <= n; i++) idk(i);
    if (ok == 0) { cout << "NO\n"; return; }

    int par[n+1]; iota(par, par+n+1, 0);
    function <int(int)> fi = [&] (int x) {
        if (x == par[x]) return x;
        return par[x] = fi(par[x]);
    };
    // O(N^2)
    for (int u = 1; u <= n; u++) {
        for (auto v : adj[u]) if (fi(u) != fi(v)) {
            par[fi(u)] = fi(v);
        }
    }
    // O(N)
    for (int i = 1; i < n; i++) if (fi(i) != fi(i+1)) { cout << "NO\n"; return; }
    // O(N^2)
    for (int i = 1; i <= n; i++) b[i] |= a[i];
    vector <pair <int, int>> E;
    // O(N^2)
    for (int i = 1; i <= n; i++) {
        for (int k = (int) mx[i].size() - 1; k >= 0; k--) {
            if (!b[i][mx[i][k].second]) { continue; }
            E.emplace_back(i, mx[i][k].second);
            for (auto &e : adj[mx[i][k].second]) b[i][e] = 0;
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


