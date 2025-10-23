#include <bits/stdc++.h>

using namespace std;

int up[20][200005], n, depth[200005];
vector <int> adj[200005];

void dfs(int u) {
    for (int x : adj[u]) {
        depth[x] = depth[u] + 1;
        dfs(x);
    }
}

int main() {
    int q;
    scanf("%d %d", &n, &q);
    for (int i = 2; i <= n; i++) {
        int x;
        scanf("%d", &x);
        adj[x].push_back(i);
        up[0][i] = x;
    }
    for (int i = 1; i < 20; i++) for (int j = 2; j <= n; j++) up[i][j] = up[i-1][up[i-1][j]];
    dfs(1);
    while (q--) {
        int a, b, uu;
        scanf("%d %d", &a, &b);
        if (depth[a] < depth[b]) swap(a, b);
        uu = depth[a] - depth[b];
        for (int i = 0; i < 20; i++) if (uu & (1 << i)) a = up[i][a];
        if (a == b) {printf("%d\n", a); continue;}
        for (int i = 19; i >= 0; i--) if (up[i][a] != up[i][b]) a = up[i][a], b = up[i][b];
        printf("%d\n", up[0][a]);
    }
}