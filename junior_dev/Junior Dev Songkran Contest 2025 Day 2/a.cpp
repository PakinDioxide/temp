/*
    author  : PakinDioxide
    created : 14/04/2025 19:39
    task    : a
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;
int n, m;
vector <tuple <ll, ll, ll, ll>> adj[mxN];
ll dis[mxN];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        ll u, v, w, l, r;
        cin >> u >> v >> w >> l >> r;
        adj[u].emplace_back(v, w, l, r);
        adj[v].emplace_back(u, w, l, r);
    }
    for (int i = 1; i <= n; i++) dis[i] = LLONG_MAX;
    priority_queue <pair <ll, ll>> q;
    q.emplace(0, 1);
    dis[1] = 0;
    while (!q.empty()) {
        auto [w, u] = q.top();
        q.pop();
        w=-w;
        if (dis[u] != w) continue;
        for (auto [v, ww, l, r] : adj[u]) if (dis[v] > (w >= l && w <= r ? r : w) + ww) q.emplace(-(dis[v] = (w >= l && w <= r ? r : w) + ww), v);
    }
    if (dis[n] != LLONG_MAX) cout << dis[n] << '\n';
    else cout << "meme_boi2 is untouchable (for now)" << '\n';
}

/*
run dijkstra from k
*/