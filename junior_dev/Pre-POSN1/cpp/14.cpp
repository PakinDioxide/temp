#include <bits/stdc++.h>

using namespace std;

vector <int> adj[1005];
pair <int, int> co[1005];
int vis[1005], edge[1005];

void dfs(int u, int p) {
    co[u] = {0, u};
    edge[u] = u;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        if (co[u] = max(co[v] + 1, co[u]);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
}