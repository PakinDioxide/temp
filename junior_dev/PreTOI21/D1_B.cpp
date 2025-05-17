/*
    author  : PakinDioxide
    created : 03/05/2025 21:25
    task    : D1_B
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;

ll n, q, st, ans[mxN], dp[mxN], cnt[mxN], dep[mxN], upp[mxN];
map <int, ll> adj[mxN];
vector <tuple <int, int, ll>> E;

void dfs1(int u, int p) {
    dp[u] = cnt[u] = ans[u] = 0;
    cnt[u] = 1;
    for (auto [v, w] : adj[u]) if (v != p) {
        dep[v] = dep[u]+1;
        dfs1(v, u);
        dp[u] += dp[v] + w * cnt[v];
        cnt[u] += cnt[v];
    }
}

void dfs2(int u, int p, ll up) {
    ans[u] = dp[u] + up;
    upp[u] = up;
    for (auto [v, w] : adj[u]) if (v != p) {
        dfs2(v, u, ans[u] - (dp[v] + w * cnt[v]) + (n - cnt[v]) * w);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q >> st;
    E.resize(n-1);
    for (auto &[x, y, w] : E) cin >> x >> y >> w, adj[x][y] = w, adj[y][x] = w;
    dfs1(st, st);
    dfs2(st, st, 0);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x; ll y;
            cin >> x >> y;
            x--;
            int u = get<0>(E[x]), v = get<1>(E[x]);
            if (dep[u] > dep[v]) swap(u, v);
            cout << ans[st] - adj[u][v]*cnt[v] + y*cnt[v] << '\n';
        } else {int x; cin >> x; cout << ans[x] << '\n';}
    }
}