#include <bits/stdc++.h>

using namespace std;

int n, a[200005];
vector <int> adj[200005];

void dec(int u, int x) {
    for (int e : adj[u]) {
        a[e] -= x;
        dec(e, x);
    }
}

int dfs(int u) {
    int mi = INT_MAX;
    for (int e : adj[u]) {
        mi = min(dfs(e), mi);
    }
    if (mi == INT_MAX) mi = a[u];
    // printf("P %d %d %d\n", u, mi, a[u]);
    if (mi > a[u] && u != 1) {/*dec(u, (mi-a[u])/2),*/ a[u] += (mi-a[u])/2;/* printf("A %d %d %d\n", u, mi, a[u]);*/ return a[u];}
    else if (u == 1) {a[u] += mi; return a[u];}
    return mi;
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        scanf("%d", &a[i]);
    }
    for (int i = 2; i <= n; i++) {
        int x;
        scanf("%d", &x);
        adj[x].push_back(i);
    }
    printf("%d\n", dfs(1));
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
}