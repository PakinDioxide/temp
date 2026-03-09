#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m, k, l; cin >> n >> m >> k >> l;
    vector <int> S(k), D(l);
    for (auto &e : S) cin >> e;
    for (auto &e : D) cin >> e;
    vector <int> s(n+1), d(n+1);
    for (auto &e : S) s[e] = 1;
    for (auto &e : D) d[e] = 1;
    vector <int> adj[n+1];
    for (int i = 0, u, v; i < m; i++) cin >> u >> v, adj[u].emplace_back(v), adj[v].emplace_back(u);
    if (k == 0) {
        int dis[n+1];
        for (auto &e : dis) e = INT_MAX;
        dis[0] = 0;
        queue <int> q;
        q.emplace(1);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto v : adj[u]) if (dis[v] > dis[u] + 1) dis[v] = dis[u] + 1, q.emplace(v);
        }
        queue <pair <int, int>> Q;
        for (auto &e : D) Q.emplace(e, dis[e]);
        int vis[n+1]; memset(vis, 0, sizeof(vis));
        while (!Q.empty()) {
            auto [u, c] = Q.front(); Q.pop();
            vis[u] = 1;
            for (auto v : adj[u]) if (!vis[v] && dis[v] == c-1) vis[v] = 1, Q.emplace(v, c-1);
        }
        for (int i = 2; i <= n; i++) cout << vis[i]; cout << '\n';
        return;
    } else {
        pair <int, int> dis[n+1];
        for (auto &[d, c] : dis) d = INT_MAX, c = INT_MIN;
        dis[1] = make_pair(0, 0);
        queue <tuple <int, int, int>> q;
        q.emplace(1, 0, 0);
        while (!q.empty()) {
            auto [u, d, c] = q.front(); q.pop();
            if (make_pair(d, c) != dis[u]) continue;
            for (auto v : adj[u]) {
                if (dis[v].first > dis[u].first + 1) {
                    dis[v] = make_pair(dis[u].first+1, dis[u].second + s[v]);
                    q.emplace(v, dis[v].first, dis[v].second);
                } else if (dis[v].first == dis[u].first + 1 && dis[v].second < dis[u].second + s[v]) {
                    dis[v] = make_pair(dis[u].first+1, dis[u].second + s[v]);
                    q.emplace(v, dis[v].first, dis[v].second);
                }
            }
        }
        vector <int> dd;
        for (auto &e : D) {
            if (dis[e].second == S.size()) {
                dd.emplace_back(e);
            }
        }
        if (dd.empty()) {
            for (int i = 1; i < n; i++) cout << 0;
            cout << '\n';
            return;
        }
        vector <int> vis(n+1);
        for (auto &e : dd) q.emplace(e, dis[e].first, dis[e].second);
        while (!q.empty()) {
            auto [u, d, c] = q.front(); q.pop();
            vis[u] = 1;
            for (auto v : adj[u]) if (!vis[v] && dis[v].first == dis[u].first - 1 && dis[v].second == dis[u].second - s[u]) {
                vis[v] = 1;
                q.emplace(v, dis[v].first, dis[v].second);
            }
        }
        for (int i = 2; i <= n; i++) cout << vis[i]; cout << '\n';
        return;
        /*
        vector <int> pth;
        int x = dd[0];
        while (1) {
            if (s[x] || x == 1) pth.emplace_back(x);
            if (prev[x] == x) break;
            x = prev[x];
        }
        reverse(pth.begin(), pth.end());
        vector <int> vis(n+1);
        auto span = [&] (int x, int y) {
            vis[x] = vis[y] = 1;
            map <int, int> disx, disy;
            disx[x] = disy[y] = 0;
            queue <int> q;
            q.emplace(x);
            int dxy = 0;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (auto v : adj[u]) if (!vis[v] && disx[v] == 0 && v != x) {
                    disx[v] = disx[u] + 1, q.emplace(u);
                    if (v == y) {
                        dxy = disx[v];
                        while (!q.empty()) q.pop();
                        break;
                    }
                }
            }
            q.emplace(y);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (auto v : adj[u]) if (!vis[v] && disy[v] == 0 && v != y) {
                    disy[v] = disy[u] + 1, q.emplace(u);
                    if (v == x) {
                        while (!q.empty()) q.pop();
                        break;
                    }
                }
            }
            for (auto &[x, y] : disx) if (disx[x] + disy[y] == dxy) vis[x] = 1;
        };
        for (int i = 0; i < pth.size() - 1; i++) span(pth[i], pth[i+1]);
        auto last = [&] () {
            int dis[n+1];
            for (auto &e : dis) e = INT_MAX;
            dis[0] = 0;
            queue <int> q;
            q.emplace(pth.back());
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (auto v : adj[u]) if (dis[v] > dis[u] + 1) dis[v] = dis[u] + 1, q.emplace(v);
            }
            queue <pair <int, int>> Q;
            for (auto &e : dd) Q.emplace(e, dis[e]);
            while (!Q.empty()) {
                auto [u, c] = Q.front(); Q.pop();
                vis[u] = 1;
                for (auto v : adj[u]) if (!vis[v] && dis[v] == c-1) vis[v] = 1, Q.emplace(v, c-1);
            }
        };
        last();
        for (int i = 2; i <= n; i++) cout << vis[i];
        cout << '\n';
        */
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T; cin >> T;
    while (T--) solve();
}
