#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n, idx, val[200005];
vector <int> adj[200005];

void dfs(int u, int p, int k) {
    if ((idx - k) != 1 && (idx - k) % 2 == 1) idx++;
    if (idx - k == 2) idx += 2;
    val[u] = idx++;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u, val[u]);
    }
}

void solve() {
    cin >> n;
    idx = 1;
    for (int i = 1; i <= n; i++) adj[i].clear();
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0, 0);
    for (int i = 1; i <= n; i++) cout << val[i] << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}