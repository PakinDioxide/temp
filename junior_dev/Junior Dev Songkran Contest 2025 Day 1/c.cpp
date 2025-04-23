/*
    author  : PakinDioxide
    created : 13/04/2025 18:09
    task    : c
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;

int n;
vector <int> adj[mxN];
ll ans[mxN], deg[mxN], mx = 0;

void dfs(int u, int p, int c) {
    ans[c]++;
    for (auto v : adj[u]) {
        if (v == p) continue;
        dfs(v, u, c+1);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
        deg[u]++, deg[v]++;
        mx = max(mx, deg[u]);
        mx = max(mx, deg[v]);
    }
    if (mx <= 2) {
        for (int i = 0; i < n; i++) {
            cout << n-i << ' ';
        }
        return 0;
    }
    for (int i = 1; i <= n; i++) dfs(i, i, 0);
    for (int i = 0; i < n; i++) cout << (i == 0 ? ans[i] : ans[i]/2) << ' ';
    cout << '\n';
}