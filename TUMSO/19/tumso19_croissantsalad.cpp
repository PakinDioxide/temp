#include <bits/stdc++.h>

using namespace std;

int par[305], vis[305][305];

int fi(int x) {
    if (x != par[x]) return par[x] = fi(par[x]);
    return x;
}

int main() {
    int n, m, cyc = 0, c = 0;
    scanf("%d %d", &n, &m);
    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (vis[u][v]) cyc++;
        else {
            vis[u][v] = vis[v][u] = 1;
            u = fi(u);
            v = fi(v);
            if (u != v) c++;
            par[u] = v;
        }
    }
    printf("%d", n-1-c+cyc);
}