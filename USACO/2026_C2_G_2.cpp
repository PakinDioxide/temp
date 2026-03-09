#include <bits/stdc++.h>
#define ll long long

using namespace std;

int cmp(const vector <pair <int, int>> &A, const vector <pair <int, int>> &B) {
    if (A.empty() && B.size()) return -1;
    else if (A.size() && B.empty()) return 1;
    else if (A.empty() && B.empty()) return 0;
    for (int i = 0; i < min((int) A.size(), (int) B.size()); i++) {
        if (A[i] == B[i]) continue;
        if (A[i].first < B[i].first) return -1;
        else if (A[i].first > B[i].first) return 1;
        else if (A[i].second < B[i].second) return -1;
        else if (A[i].second > B[i].second) return 1;
    }
    if (A.size() < B.size()) return -1;
    else if (A.size() == B.size()) return 0;
    else return 1;
}

int cmp2(const vector <pair <int, int>> &A, const vector <pair <int, int>> &B) {
    if (A.empty() && B.size()) return -1;
    else if (A.size() && B.empty()) return 1;
    else if (A.empty() && B.empty()) return 0;
    for (int i = 0; i < min((int) A.size(), (int) B.size()); i++) {
        if (A[i] == B[i]) continue;
        if (A[i].first < B[i].first) return -1;
        else if (A[i].first > B[i].first) return 1;
        else if (A[i].second < B[i].second) return -1;
        else if (A[i].second > B[i].second) return 1;
    }
    return 1;
}


void solve() {
    int n, m; cin >> n >> m;
    vector <pair <int, int>> adj[n+1];
    for (int i = 0; i < m; i++) {
        int u, v; char c; cin >> u >> v >> c;
        adj[u].emplace_back(v, 1 + c - 'a');
        adj[v].emplace_back(u, 1 + c - 'a');
    }
    pair <int, vector <pair <int, int>>> dp[n+1];
    for (auto &[x, y] : dp) x = INT_MAX;
    dp[1].first = 0;
    queue <tuple <int, int, vector <pair <int, int>>>> q; // u, c, val
    q.emplace(1, 0, dp[1].second);
    while (!q.empty()) {
        auto [u, c, val] = q.front(); q.pop();
        if (dp[u] != make_pair(c, val)) continue;
        c++;
        for (auto [v, w] : adj[u]) if (val.empty() || val.back().second >= w) {
            vector <pair <int, int>> vv = val;
            if (vv.empty() || vv.back().second > w) vv.emplace_back(c, w);
            if ((dp[v].first == 0 || dp[v].first == INT_MAX || cmp(vv, dp[v].second) == -1 || (cmp(vv, dp[v].second) == 0 && c < dp[v].first))) {
                dp[v].first = c;
                swap(vv, dp[v].second);
                q.emplace(v, c, dp[v].second);
            }
        }
    }
    vector <pair <int, int>> mn;
    int M = 27;
    for (auto &[v, w] : adj[1]) M = min(M, w);
    mn.emplace_back(1, M);
    for (int i = 1; i <= n; i++) if (dp[i].first < INT_MAX && dp[i].second.size() && cmp2(mn, dp[i].second) == 1) mn = dp[i].second;
    for (int i = 1; i <= n; i++) {
        if (i == 1) cout << 0 << " \n"[(i==n)];
        else cout << (dp[i].first == INT_MAX || cmp2(mn, dp[i].second) == -1 ? -1 : dp[i].first) << " \n"[(i==n)];
        // for (auto &[x, y] : dp[i].second) cout << i << ' ' << x << ' ' << y << '\n';
    }
    // for (auto &[x, y] : mn) cout << "MN " << ' ' << x << ' ' << y << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T; cin >> T;
    while (T--) solve();
}
