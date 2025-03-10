#include <bits/stdc++.h>

using namespace std;

int adj[65540][2];
int p[65540], n, idx = 0;

int dfs(int u) {
    if (u != p[idx]) return 0;
    // printf("%d ", u);
    if (adj[u][0] == 0) return 1;
    idx++;
    if (adj[u][0] == p[idx]) {
        if (dfs(adj[u][0])) {idx++; return dfs(adj[u][1]);}
    } else if (adj[u][1] == p[idx]) {
        if (dfs(adj[u][1])) {idx++; return dfs(adj[u][0]);}
    }
    return 0;
}

void solve() {
    int q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) adj[i][0] = 0;
    for (int i = 2; i <= n; i++) {
        int x;
        scanf("%d", &x);
        if (adj[x][0] = 0) adj[i][0] = i;
        else adj[x][1] = x;
    }
    for (int i = 0; i < n; i++) scanf("%d", &p[i]);
    while (q--) {
        int x, y;
        scanf("%d %d", &x, &y);
        swap(p[x-1], p[y-1]);
        idx = 0;
        if (dfs(1)) printf("YES\n");
        else printf("NO\n");
    }
}

int32_t main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
}