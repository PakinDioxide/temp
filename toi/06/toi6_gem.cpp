/*
    author  : PakinDioxide
    created : 10/04/2025 03:35
    task    : toi6_gem
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int m, n;
    cin >> m >> n;
    vector <int> adj[n+5], adjt[n+5], q;
    pair <int, int> E[m];
    int vis[n+5], neg[n+5], idx = 0;
    memset(vis, 0, sizeof(vis));
    for (auto &[x, y] : E) cin >> x >> y;
    for (int i = 0; i < n/2; i++) {
        int x, y;
        cin >> x >> y;
        neg[x] = y, neg[y] = x;
    }
    for (auto &[x, y] : E) {
        adj[neg[x]].emplace_back(y);
        adj[neg[y]].emplace_back(x);
        adjt[x].emplace_back(neg[y]);
        adjt[y].emplace_back(neg[x]);
    }
    function <void(int)> dfs1 = [&] (int u) {
        vis[u] = 1;
        for (auto v : adj[u]) if (!vis[v]) dfs1(v);
        q.emplace_back(u);
    };    
    function <void(int)> dfs2 = [&] (int u) {
        vis[u] = idx;
        for (auto v : adjt[u]) if (!vis[v]) dfs2(v);
    };
    for (int i = 1; i <= n; i++) if (!vis[i]) dfs1(i);
    reverse(q.begin(), q.end());
    memset(vis, 0, sizeof(vis));
    for (auto &e : q) if (!vis[e]) ++idx, dfs2(e);
    for (int i = 1; i <= n; i+=2) if (vis[i] == vis[neg[i]]) { cout << 'N'; return; }
    cout << 'Y';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    for (int i = 0; i < 5; i++) solve();
    cout << '\n';
}

/*
    each value has only one forbidden pair ???

    so each position can be value x, y
        can it be (x v y)?
        = x v y
        = ~x -> y
        = ~y -> x

    let x, y be the forbidden pair
        = ~(x ^ y)
        = ~x v ~y
        = x -> ~y
        = y -> ~x
*/