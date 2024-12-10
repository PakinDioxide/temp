#include <bits/stdc++.h>

using namespace std;

int n, m, a[200005], idx[200005], fen[200005], siz[200005], cnt = 1;
vector <int> adj[200005];

void dfs(int u, int p) {
    idx[u] = cnt;
    fen[cnt] = fen[cnt&(-cnt)] + a[u];
    int st = cnt++;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
    siz[st] = cnt-st-1;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    dfs(1, -1);
    while (m--) {
        int x;
        scanf("%d", &x);
        if (x == 1) {
            int s, x;
            scanf("%d %d", &s, &x);
            for (int id = idx[s]; id <= n; id += id & (-id)) fen[id] += x - a[s];
            a[s] = x;
        } else {
            int s, sum = 0;
            scanf("%d", &s);
            for (int id = idx[s] + siz[idx[s]]; id > 0; id -= id & (-id)) sum += fen[id];
            printf("%d ", sum);
            for (int id = idx[s] - 1; id > 0; id -= id & (-id)) sum -= fen[id];
            printf("%d\n", sum);
        }
    }
}