#include <bits/stdc++.h>

using namespace std;

vector <int> adj[5005], adj2[5005];
int par[5005];
int curr[5005];
int n;

pair <int, int> dfs(int u, int p) {
    int c = 0;
    for (int e : adj[u]) {
        printf("? %d\n", e);
        fflush(stdout);
        int x;
        scanf("%d", &x);
        if (x == 0) c++;
        else {
            pair <int, int> k = dfs(e, u);
            int x = u;
            while (k.second--) x = par[x];
            return {x, 0};
        }
    }
    return {1, c};
}

void make_tree(int u, int p) {
    for (int e : adj2[u]) {
        if (e == p) continue;
        adj[u].push_back(e);
        par[e] = u;
        make_tree(e, u);
    }
}

void jump(int u) {
    if (u != 1) curr[par[u]] += curr[u], curr[u] = 0;
    for (int e : adj[u]) {
        jump(e);
    }
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) adj[i].clear(), adj2[i].clear(), curr[i-1] = 1;
    par[1] = 1;
    for (int i = 0; i < n-1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj2[u].emplace_back(v);
        adj2[v].emplace_back(u);
    }
    make_tree(1, 1);
    printf("! %d\n", dfs(1, 1).first);
    fflush(stdout);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
}