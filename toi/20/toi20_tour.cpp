#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, l;
    cin >> n >> m >> l;
    vector <tuple <int, int, ll>> adj[n+5];
    while (l--) {int t; cin >> t;}
    while (m--) {
        int u, v, s; ll w;
        cin >> u >> v >> s >> w;
        adj[u].emplace_back(v, s, w);
    }
    int vis[n+5];
    vector <pair <ll, ll>> dp[n+5];
    queue <int> q;
    memset(vis, 0, sizeof(vis));
    q.push(1);
    dp[1].emplace_back(0, 0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto [v, s, w] : adj[u]) {
            for (auto [x, y] : dp[u]) {
                if (s == 1) dp[v].emplace_back(x+w, y);
                else dp[v].emplace_back(x, y+w);
                if (!vis[v]) q.push(v);
                vis[v] = 1;
            }
        }
    }
    sort(dp[n].begin(), dp[n].end());
    multiset <pair <ll, ll>> s;
    ll k = LLONG_MAX, idx = 0;
    for (auto [x, y] : dp[n]) {
        ll d = ceil(sqrt(k));
        while (idx < dp[n].size() && x - dp[n][idx].first > d) s.erase(s.find({dp[n][idx].second, dp[n][idx].first})), idx++;
        auto it = s.lower_bound({y-d, LLONG_MIN});
        while (it != s.end()) {
            auto [yy, xx] = *it;
            if (yy - y > d) break;
            k = min(k, (yy-y)*(yy-y) + (xx-x)*(xx-x));
            it++;
        }
        s.emplace(y, x);
    }
    cout << k << '\n';
}