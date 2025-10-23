#include <bits/stdc++.h>

using namespace std;

int vis[100005][10005]

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, k, m;
    cin >> n >> k >> m;
    vector <tuple <int, int, int>> adj[n+1];
    int sp[k];
    for (int i = 0; i < k; i++) cin >> a[i];
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w, 0);
        adj[v].emplace_back(u, w, 0);
    }
    int s = sp[0];
    pair <int, int> dis[n+1];
}