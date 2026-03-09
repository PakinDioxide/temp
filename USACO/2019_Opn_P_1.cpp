#include "grader.h"
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;

vector <int> adj[mxN];
int n, cc[mxN][2], dep[mxN], up[30][mxN], it = 0;

void dfs(int u, int p, int k) {
    up[0][u] = p;
    dep[u] = dep[p]+1;
    for (auto v : adj[u]) if (v != p) dfs(v, u, k);
    reverse(adj[u].begin(), adj[u].end());
    cc[u][k] = ++it;
}

int LCA(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    int k = dep[u] - dep[v];
    for (int i = 0; i < 30; i++) if (k & (1 << i)) u = up[i][u];
    if (u == v) return u;
    for (int i = 29; i >= 0; i--) if (up[i][u] != up[i][v]) u = up[i][u], v = up[i][v];
    return up[0][u];
}

void addRoad(int u, int v) {
    u++, v++;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
}

void buildFarms() {
    it = 0, dfs(1, 0, 0);
    it = 0, dfs(1, 0, 1);
    n = getN();
    for (int c = 1; c < 30; c++) for (int i = 1; i <= n; i++) up[c][i] = up[c-1][up[c-1][i]];
    for (int i = 1; i <= n; i++) setFarmLocation(i-1, cc[i][0], cc[i][1]);// cout << cc[i][0] << ' ' << cc[i][1] << '\n';
}

// void addBox(int X1, int Y1, int X2, int Y2) {
//     cout << X1 << ' ' << Y1 << ' ' << X2 << ' ' << Y2 << '\n';
// }

void notifyFJ(int u, int v) {
    u++, v++;
    if (cc[u][0] > cc[v][0]) swap(u, v);
    int lca = LCA(u, v);
    if (lca == v) {
        addBox(cc[u][0], cc[u][1], cc[lca][0], cc[lca][1]);
    } else {
        addBox(cc[u][0], cc[u][1], cc[lca][0], cc[lca][1]);
        addBox(cc[v][0], cc[v][1], cc[lca][0], cc[u][1]);
    }
}

// int main() {
//     ios::sync_with_stdio(0), cin.tie(0);
//     addRoad(1, 2);
//     addRoad(1, 3);
//     addRoad(2, 4);
//     addRoad(2, 5);
//     addRoad(2, 6);
//     addRoad(6, 7);
//     addRoad(6, 8);
//     addRoad(3, 9);
//     addRoad(3, 10);
//     buildFarms();
//     notifyFJ(9, 3);
// }