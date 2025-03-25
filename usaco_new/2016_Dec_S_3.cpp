/*
    author  : PakinDioxide
    created : 22/03/2025 11:49
    task    : 2016_Dec_S_3
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    int n;
    cin >> n;
    vector <int> adj[n];
    tuple <int, int, int> a[n];
    for (auto &[x, y, p] : a) cin >> x >> y >> p;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        auto [x, y, p] = a[i];
        auto [xx, yy, pp] = a[j];
        if ((x-xx)*(x-xx) + (y-yy)*(y-yy) > p*p) continue;
        adj[i].push_back(j);
    }
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int vis[n], cnt = 0;
        memset(vis, 0, sizeof(vis));
        queue <int> q;
        q.emplace(i);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (vis[u]) continue;
            vis[u] = 1;
            cnt++;
            for (int v : adj[u]) q.emplace(v);
        }
        mx = max(mx, cnt);
    }
    cout << mx << '\n';
}