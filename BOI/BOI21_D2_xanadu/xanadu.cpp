#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;

int n, a[mxN];
vector <int> adj[mxN];
pair <int, int> dp[mxN][2];

void dfs(int u, int p) {
    int C[2] = {0, 0}, CC[2] = {0, 0};
    for (auto v : adj[u]) if (v != p) {
        dfs(v, u);
        if (dp[v][0].first == INT_MAX) C[0] = INT_MAX;
        if (dp[v][1].first == INT_MAX) C[1] = INT_MAX;
        if (C[0] < INT_MAX && dp[v][0].first < INT_MAX) {
            CC[0] ^= dp[v][0].second;
            C[0] += dp[v][0].first;
        }
        if (C[1] < INT_MAX && dp[v][1].first < INT_MAX) {
            CC[1] ^= dp[v][1].second;
            C[1] += dp[v][1].first;
        }
    }
    if (C[0] == INT_MAX && C[1] == INT_MAX) {
        cout << "impossible\n";
        exit(0);
    }
    dp[u][0] = dp[u][1] = {INT_MAX, 0};
    if (a[u] == 0) {
        dp[u][CC[0]] = min(dp[u][CC[0]], make_pair(C[0], 0));
        dp[u][CC[1] ^ 1] = min(dp[u][CC[1] ^ 1], make_pair(C[1] + 1, 1));
    } else {
        dp[u][CC[0] ^ 1] = min(dp[u][CC[0] ^ 1], make_pair(C[0], 0));
        dp[u][CC[1]] = min(dp[u][CC[1]], make_pair(C[1] + 1, 1));
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1, u, v; i < n; i++) cin >> u >> v, adj[u].emplace_back(v), adj[v].emplace_back(u);
    for (int i = 1; i <= n; i++) cin >> a[i];
    dfs(1, 1);
    if (dp[1][0].first == INT_MAX) cout << "impossible\n";
    else cout << dp[1][0].first << '\n';
    /*
    int mn = INT_MAX;
    for (int k = 0; k < (1 << n); k++) {
        int b[n+1]; for (int i = 1; i <= n; i++) b[i] = a[i];
        int c = 0;
        for (int i = 0; i < n; i++) if (k & (1 << i)) { c++; for (auto &v : adj[i+1]) b[v] ^= 1; b[i+1] ^= 1; }
        int mx = 0;
        for (int i = 1; i <= n; i++) mx = max(mx, b[i]);
        if (mx == 0) if (mn > c) {
            mn = c;
            for (int i = 0; i < n; i++) cout << ((k >> i) & 1) << ' '; cout << '\n';
        }
    }
    if (mn == INT_MAX) cout << "impossible\n";
    else cout << mn << '\n';
    */
}
