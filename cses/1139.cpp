#include <bits/stdc++.h>

using namespace std;

int c[200005], ans[200005];
vector <int> adj[200005];
set <int> s[200005];

void dfs(int u, int p) {
    s[u].insert(c[u]);
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        if (s[u].size() < s[v].size()) swap(s[u], s[v]);
        for (int x : s[v]) s[u].insert(x);
    }
    ans[u] = s[u].size();
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1);
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
}