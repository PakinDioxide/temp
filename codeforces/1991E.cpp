#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector <int> adj[n+1];
    for (int i = 0, u, v; i < m; i++) cin >> u >> v, adj[u].emplace_back(v), adj[v].emplace_back(u);
    int c[n+1], ok = 1; memset(c, 0, sizeof(c));
    queue <pair <int, int>> q; q.emplace(1, 1); c[1] = 1;
    while (!q.empty()) {
        auto [u, x] = q.front(); q.pop(); x = (x == 1 ? 2 : 1);
        for (auto v : adj[u]) {
            if (c[v] && c[v] == x) continue;
            else if (c[v] && c[v] != x) { ok = 0; break; }
            else q.emplace(v, c[v] = x);
        }
        if (ok == 0) break;
    }
    vector <int> O, E;
    for (int i = 1; i <= n; i++) {
        if (c[i] == 1) O.emplace_back(i);
        else E.emplace_back(i);
    }
    if (ok == 0) {
        cout << "Alice" << endl;
        int x, y;
        for (int i = 0; i < n; i++) cout << 1 << ' ' << 2 << endl, cin >> x >> y;
    } else {
        cout << "Bob" << endl;
        int x, y;
        for (int i = 1; i <= n; i++) {
            cin >> x >> y;
            if (x == 1 || y == 1) {
                if (!O.empty()) {
                    cout << O.back() << ' ' << 1 << endl;
                    O.pop_back();
                    continue;
                }
            }
            if (x == 2 || y == 2) {
                if (!E.empty()) {
                    cout << E.back() << ' ' << 2 << endl;
                    E.pop_back();
                    continue;
                }
            }
            if (!O.empty()) cout << O.back() << ' ' << 3 << endl, O.pop_back();
            else cout << E.back() << ' ' << 3 << endl, E.pop_back();
        }
    }
}

int main() {
    // ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}