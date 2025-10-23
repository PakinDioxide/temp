#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;

int n, m, idx[mxN];
ll a[mxN];
vector <int> adj[mxN];
vector <pair <ll, int>> v;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i], v.emplace_back(a[i], i);
    for (int i = 0, u, v; i < m; i++) cin >> u >> v, adj[u].emplace_back(v), adj[v].emplace_back(u);
    ll L = 0, R = 1e8, ans = 0;
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) idx[v[i].second] = i;
    while (L <= R) {
        ll X = L + (R-L)/2;
        vector <int> adt[mxN];
        for (int i = 0; i < n && v[i].first <= X/2; i++) {
            int u = v[i].second;
            for (auto V : adj[u]) if (idx[V] < i) adt[u].emplace_back(V), adt[V].emplace_back(u); 
        }
        queue <pair <int, int>> q;
        q.emplace(0, 1);
        int vis[mxN]; memset(vis, 0, sizeof(vis));
        vis[1] = 1;
        while (!q.empty()) {
            auto [c, u] = q.front(); q.pop();
            if (X == 4) cout << c << ' ' << u << '\n';
            if (u == n) {
                if (c <= X) ans = X, R = X-1;
                else L = X+1;
                break;
            }
            for (auto v : adt[u]) if (!vis[v]) vis[v] = 1, q.emplace(c+1, v);
        }
        if (vis[n] == 0) L = X+1;
    }
    cout << ans << '\n';
}