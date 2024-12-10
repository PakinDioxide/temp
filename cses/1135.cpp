#include <bits/stdc++.h>

using namespace std;

int depth[200005], up[20][200005];
vector <int> adj[200005];

void dfs(int u, int p) {
    for (int v : adj[u]) {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        up[0][v] = u;
        dfs(v, u);
    }
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1);
    for (int i = 1; i < 20; i++) for (int j = 2; j <= n; j++) up[i][j] = up[i-1][up[i-1][j]];
    while (q--) {
        int a, b, ans = 0, uu;
        scanf("%d %d", &a, &b);
        if (depth[a] < depth[b]) swap(a, b);
        ans = depth[a] + depth[b];
        uu = depth[a] - depth[b];
        for (int i = 0; i < 20; i++) if (uu & (1 << i)) a = up[i][a];
        if (a == b) {printf("%d\n", ans - 2*depth[a]); continue;}
        for (int i = 19; i >= 0; i--) if (up[i][a] != up[i][b]) a = up[i][a], b = up[i][b];
        printf("%d\n", ans - 2*depth[up[0][a]]);
    }
}