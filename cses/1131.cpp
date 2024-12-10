#include <bits/stdc++.h>

using namespace std;

vector <int> adj[200005];
int dis[200005], l[200005];

void dfs(int u, int p) {
    dis[u] = 0;
    l[u] = u;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        if (dis[v] > dis[u]) {
            dis[u] = dis[v];
            l[u] = l[v];
        }
    }
    dis[u]++;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1);
    int k = l[1];
    dfs(k, -1);
    printf("%d", dis[k]-1);
}