#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 505;

int n, m, par[mxN], vis[mxN];
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
        q.emplace(1), vis[1] = 1;
        memset(vis, 0, sizeof(vis)), memset(par, 0, sizeof(par));
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (u == n) return 1;
            for (int v : adj[u]) if (cap[u][v] > 0 && !vis[v]) vis[v] = 1, q.emplace(v), par[v] = u;
        }
        return 0;
    };
    ll ans = 0;
    while (bfs()) {
        vector <int> v;
        v.emplace_back(n);
        ll mn = LLONG_MAX;
        while (v.back() != 1) mn = min(mn, cap[par[v.back()]][v.back()]), v.emplace_back(par[v.back()]);
        for (int i = 0; i < v.size()-1; i++) cap[v[i+1]][v[i]] -= mn, cap[v[i]][v[i+1]] += mn;
        ans += mn;
    }
    cout << ans << '\n';
}

