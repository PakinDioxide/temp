#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;

vector <int> adj[mxN];
vector <pair <int, int>> adt[mxN];

void solve() {
    int n, m, q; cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) adj[i].clear(), adt[i].clear();
    for (int i = 0, u, v; i < m; i++) cin >> u >> v, adt[v].emplace_back(u, 1), adj[u].emplace_back(v);
    int dp[n+1][2]; for (int i = 1; i <= n; i++) dp[i][0] = max(1, (int) adj[i].size()), dp[i][1] = 0;
    auto bfs = [&] (int st) {
        queue <int> q;
        if (dp[st][1] == 1 && dp[st][0] == 0) return;
        dp[st][1] = 1, dp[st][0] = 0;
        q.emplace(st);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto &[v, w] : adt[u]) {
                int cng = 0;
                if (w && dp[v][0] && dp[u][1] == 1) {
                    w = 0;
                    dp[v][0]--;
                    if (dp[v][0] == 0) cng = 1;
                }
                if (dp[v][1] == 0 && dp[u][0] == 0) dp[v][1] = 1, cng = 1;
                if (cng) q.emplace(v);
            }
        }
    };
    while (q--) {
        int t, u; cin >> t >> u;
        if (t == 1) bfs(u);
        else cout << (dp[u][0] == 0 ? "NO\n" : "YES\n");
        // for (int i = 1; i <= n; i++) cout << dp[i][0] << ' '; cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}
