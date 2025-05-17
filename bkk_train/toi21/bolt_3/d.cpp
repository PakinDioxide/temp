/*
    author  : PakinDioxide
    created : 01/05/2025 13:39
    task    : d
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 50005, sqT = 325;

vector <int> adj[mxN], s;
int dis[mxN], mp[mxN];
ll dp[sqT][mxN], P[mxN];

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    s.clear();
    for (int i = 0; i < n; i++) adj[i].clear(), dis[i] = INT_MAX, mp[i] = P[i] = 0;
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    queue <pair <int, int>> Q;
    Q.emplace(0, 0); dis[0] = 0;
    while (!Q.empty()) {
        int w, u; tie(w, u) = Q.front(); Q.pop();
        if (dis[u] != w) continue;
        if (dis[u]) mp[dis[u]]++;
        for (auto v : adj[u]) if (dis[v] > dis[u] + 1) Q.emplace(dis[v] = dis[u] + 1, v);
    }
    for (int i = 1; mp[i]; i++) s.emplace_back(mp[i]);
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    int it = 1;
    for (int i = 1; i <= s.size(); i++) dp[i][0] = 0;
    for (auto &i : s) {for (int j = 1; j <= n; j++) dp[it][j] = dp[it][j-1] + (mp[j] == i); it++; }
    while (q--) {
        int l, r; ll x; int a, b;
        cin >> l >> r >> x >> a >> b;
        for (int i = 0; i < s.size(); i++) if (l <= s[i] && s[i] <= r) P[i+1] += x;
        ll sum = 0;
        for (int i = 1; i <= s.size(); i++) sum += P[i] * (dp[i][b] - dp[i][a-1]);
        cout << sum << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
