#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    // BRUTEFORCE O(M^2)
    int N; cin >> N;
    vector <int> adj[N+1];
    for (int i = 1, u, v; i < N; i++) cin >> u >> v, adj[u].emplace_back(v),adj[v].emplace_back(u);
    vector <int> dep(N+1);
    vector <vector <int>> up(25, vector <int> (N+1));
    function <void(int, int)> dfs = [&] (int u, int p) {
        for (auto v : adj[u]) if (v != p) up[0][v] = u, dep[v] = dep[u] + 1, dfs(v, u);
    };
    dfs(1, 0);
    for (int c = 1; c < 25; c++) for (int i = 1; i <= N; i++) up[c][i] = up[c-1][up[c-1][i]];
    auto LCA = [&] (int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);
        int k = dep[u] - dep[v];
        for (int i = 0; i < 25; i++) if (k & (1 << i)) u = up[i][u];
        if (u == v) return u;
        for (int i = 24; i >= 0; i--) if (up[i][u] != up[i][v]) u = up[i][u], v = up[i][v];
        return up[0][u];
    };
    auto IN_PATH = [&] (int u, int v, int x) {
        int lca = LCA(u, v);
        return (LCA(x, lca) == lca && (LCA(u, x) == x || LCA(v, x) == x));
    };
    int M; cin >> M;
    vector <pair <int, int>> Q(M);
    for (auto &[u, v] : Q) cin >> u >> v;
    int OK = 1;
    for (int i = 0; i < M; i++) for (int j = i+1; j < M; j++) {
        auto [S1, E1] = Q[i];
        auto [S2, E2] = Q[j];
        if ((IN_PATH(S1, E1, S2) && IN_PATH(S1, E1, E2)) || (IN_PATH(S2, E2, S1) && IN_PATH(S2, E2, E1)) || (IN_PATH(S1, E1, E2) && IN_PATH(S2, E2, E1)) || (IN_PATH(S1, E1, S2) && IN_PATH(S2, E2, S1))) { cout << "NO\n"; return; }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

/*
4 case where cant
1. S1 S2 E2 E1
2. S2 S1 E1 E2
3. S1 E2 E1 S2
4. E2 S1 S2 E1

S Diff, T Diff

Brute Force : O(M^2)
*/
