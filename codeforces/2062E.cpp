#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector <int> adj[400005];
int co[400005], pcnt[400005], w[400005], fen[400005], n;

void add(int idx, int x) {
    for (int i = idx; i <= n; i += i & (-i)) fen[i] += x;
}

int sum(int idx) {
    int sum = 0;
    for (int i = idx; i > 0; i -= i & (-i)) sum += fen[i];
    return sum;
}

void dfs(int u, int p) {
    add(n-w[u]+1, 1);
    for (int v : adj[u]) {
        if (v == p) continue;
        co[v] = sum(n-w[v]+1);
        pcnt[v] = pcnt[u]+1;
        dfs(v, u);
    }
    add(n-w[u]+1, -1);
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> w[i], adj[i].clear(), co[i] = pcnt[i] = 0;
    for (int i = 1, u, v; i < n; i++) cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);
    dfs(1, 0);
    for (int i = 1; i <= n; i++) cout << co[i] << ' ';
    cout << '\n';
    for (int i = 1; i <= n; i++) cout << pcnt[i] << ' ';
    cout << '\n' << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}