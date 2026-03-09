#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 505;

int n, m, lv[mxN], nxt[mxN], vis[mxN];
ll cap[mxN][mxN];
vector <int> adj[mxN];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    while (m--) {
        int u, v; ll w; cin >> u >> v >> w;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
        cap[u][v] += w;
    }
    auto bfs = [&] () {
        queue <int> q;
        q.emplace(1);
        memset(lv, 0, sizeof(lv));
        memset(vis, 0, sizeof(vis));
        lv[1] = vis[1] = 1;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            // if (u == n) return 1;
            for (auto v : adj[u]) if (!vis[v] && cap[u][v] > 0) vis[v] = 1, lv[v] = lv[u] + 1, q.emplace(v);
        }
        return vis[n];
    };
    function <ll(int, ll)> dfs = [&] (int u, ll mn) {
        if (u == n) { return mn; }
        for (; nxt[u] < adj[u].size(); nxt[u]++) {
            int v = adj[u][nxt[u]];
            if (cap[u][v] > 0 && lv[v] == lv[u] + 1) {
                ll k = dfs(v, min(mn, cap[u][v]));
                if (k > 0) { cap[u][v] -= k; cap[v][u] += k; return k; }
            }
        }
        return 0LL;
    };
    ll ans = 0;
    while(bfs()) {
        memset(nxt, 0, sizeof(nxt));
        ll k;
        while (k = dfs(1, LLONG_MAX)) {
            ans += k;
        }
    }
    cout << ans << '\n';
}

