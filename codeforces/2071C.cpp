#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n, st, en;
vector <int> adj[200005];
int dep[200005];
vector <pair <int, int>> V;

void dfs(int u, int p) {
    for (int v : adj[u]) {
        if (v == p) continue;
        dep[v] = dep[u] + 1;
        V.emplace_back(dep[v], v);
        dfs(v, u);
    }
}

void solve() {
    cin >> n >> st >> en;
    V.clear();
    for (int i = 1; i <= n; i++) adj[i].clear(), dep[i] = 0;
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(en, 0);
    V.emplace_back(0, en);
    sort(V.begin(), V.end());
    for (int i = n-1; i >= 0; i--) cout << V[i].second << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}