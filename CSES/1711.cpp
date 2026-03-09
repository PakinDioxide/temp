#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 505;

int n, m, par[mxN], vis[mxN];
vector <int> adj[mxN];
ll cap[mxN][mxN];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    while (m--) {
        int u, v; cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
        cap[u][v]++;
    }
    auto bfs = [&] () {
        queue <int> q;
        memset(vis, 0, sizeof(vis)), memset(par, 0, sizeof(par));
        q.emplace(1), vis[1] = 1;
        while (!q.empty())  {
            int u = q.front(); q.pop();
            if (u == n) return 1;
            for (auto v : adj[u]) if (cap[u][v] > 0 && !vis[v]) par[v] = u, vis[v] = 1, q.emplace(v);
        }
        return 0;
    };
    vector <vector <int>> ans;
    while (bfs()) {
        vector <int> v;
        v.emplace_back(n);
        ll mn = LLONG_MAX;
        while (v.back() != 1) mn = min(mn, cap[par[v.back()]][v.back()]), v.emplace_back(par[v.back()]);
        for (int i = 0; i < v.size() - 1; i++) cap[v[i+1]][v[i]] -= mn, cap[v[i]][v[i+1]] += mn;
        reverse(v.begin(), v.end());
        while (mn--) ans.emplace_back(v);
    }
    cout << ans.size() << '\n';
    for (auto &x : ans) {
        cout << x.size() << '\n';
        for (auto &e : x) cout << e << ' '; 
        cout << '\n';
    }
}
