#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    // freopen("gathering.in", "r", stdin);
    // freopen("gathering.out", "w", stdout);
    int n, m; cin >> n >> m;
    vector <int> adj[n+1];
    int deg[n+1], F[n+1], ; memset(F, 0, sizeof(F)), memset(deg, 0, sizeof(deg));
    for (int i = 0, u, v; i < n; i++) cin >> u >> v, adj[u].emplace_back(v), adj[v].emplace_back(u), deg[u]++, deeg[v]++;
    queue <int> q;
    for (int i = 1; i <= n; i++) if (deg[i] == 1) q.emplace(i);
}