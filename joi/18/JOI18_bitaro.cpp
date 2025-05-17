#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;

int n, m, q, k, ok[mxN];
set <pair <int, int>> dp[mxN];
vector <int> adj[mxN];

int main() {
    cin >> n >> m >> q; k = sqrt(n);
    for (int i = 0, u, v; i < m; i++) cin >> u >> v, adj[max(u, v)].emplace_back(min(u, v));
    for (int u = 1; u <= n; u++) {
        dp[u].emplace(0, u);
        for (auto v : adj[u]) for (auto &e : dp[v]) {
            if (dp[u].size() == k && -(*prev(dp[u].end())).first >= -e.first+1) break;
            dp[u].emplace(e.first-1, e.second);
            if (dp[u].size() > k) dp[u].erase(prev(dp[u].end()));
        }
    }
    while (q--) {
        int u, y; cin >> u >> y;
        vector <int> X;
        for (int i = 0, e; i < y; i++) { cin >> e; if (e <= u) X.emplace_back(e), ok[e] = 1; }
        y = X.size();
        if (y < k) {
            auto it = dp[u].begin();
            while (it != dp[u].end() && ok[(*it).second]) it++;
            if (it == dp[u].end()) cout << -1 << '\n';
            else cout << -(*it).first << '\n';
        } else {
            vector <int> DP(n+1, INT_MIN);
            for (int i = 1; i <= u; i++) { if (!ok[i]) DP[i] = 0; for (auto v : adj[i]) DP[i] = max(DP[i], DP[v]+1); }
            cout << max(-1, DP[u]) << '\n';
        }
        for (auto &e : X) ok[e] = 0;
    }
}
