#include <bits/stdc++.h>

using namespace std;

int vis[1000005], ok = 1;
vector <int> adj[1000005];

void dfs(int u, int p) {
    if (!ok) return;
    vis[u] = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (vis[v]) {ok = 0; return;}
        dfs(v, u);
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
    // printf("%d", !ok);
    return (!ok);
}