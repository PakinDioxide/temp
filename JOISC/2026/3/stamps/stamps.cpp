#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 5e5+5;

int n, d, t[mxN];
vector <int> adj[mxN];

int dfs(int u, int p, int ok, int c) {
    if (t[u] <= c) ok = 1;
    if (c == d) return ok;
    int cnt =  ok;
    for (auto v : adj[u]) if (v != p) cnt += dfs(v, u, ok, c+1);
    return cnt;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> d;
    for (int i = 1; i <= n; i++) cin >> t[i];
    for (int i = 1, u, v; i < n; i++) cin >> u >> v, adj[u].emplace_back(v), adj[v].emplace_back(u);
    for (int i = 1; i <= n; i++) cout << dfs(i, i, 0, 0) << '\n';
}
