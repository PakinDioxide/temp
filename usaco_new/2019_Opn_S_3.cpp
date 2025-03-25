/*
    author  : PakinDioxide
    created : 22/03/2025 11:59
    task    : 2019_Opn_S_3
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    pair <ll, ll> a[n+1];
    for (int i = 1; i <= n; i++) {auto &[x, y] = a[i]; cin >> x >> y;}
    vector <int> adj[n+1];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll mn = LLONG_MAX;
    int vis[n+1];
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        ll mnx = LLONG_MAX, mxx = 0, mny = LLONG_MAX, mxy = 0;
        queue <int> q;
        q.emplace(i);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (vis[u]) continue;
            vis[u] = 1;
            mnx = min(mnx, a[u].first);
            mxx = max(mxx, a[u].first);
            mny = min(mny, a[u].second);
            mxy = max(mxy, a[u].second);
            for (int v : adj[u]) q.emplace(v);
        }
        mn = min(mn, 2*((mxx-mnx)+(mxy-mny)));
    }
    cout << mn << '\n';
}