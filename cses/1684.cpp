/*
    author  : PakinDioxide
    created : 10/04/2025 02:55
    task    : 1684
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;

int n, m, vis[mxN], g[mxN], val[mxN];
vector <int> adj[mxN], adjt[mxN], kosa, gc[mxN];

void dfs1(int u) {
    vis[u] = 1;
    for (auto v : adj[u]) if (!vis[v]) dfs1(v);
    kosa.emplace_back(u);
}

void dfs2(int u, int k) {
    g[u] = k;
    gc[k].emplace_back(u);
    for (auto v : adjt[u]) if (!g[v]) dfs2(v, k);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        char x, y;
        int u, v, nu, nv;
        cin >> x >> u >> y >> v;
        nu = (x == '-'), nv = (y == '-');
        // a v b == ~a -> b / ~b -> a
        adj[2*u+!nu-1].emplace_back(2*v+nv-1);
        adj[2*v+!nv-1].emplace_back(2*u+nu-1);
        adjt[2*u+nu-1].emplace_back(2*v+!nv-1);
        adjt[2*v+nv-1].emplace_back(2*u+!nu-1);
    }
    for (int i = 1; i <= 2*n; i++) if (!vis[i]) dfs1(i);
    reverse(kosa.begin(), kosa.end());
    int idx = 0;
    for (auto &i : kosa) if (!g[i]) dfs2(i, ++idx);
    for (int i = 1; i <= 2*n; i+=2) if (g[i] == g[i+1]) { cout << "IMPOSSIBLE\n"; return 0; }
    for (int i = 1; i <= 2*n; i++) val[i] = -1;
    for (int i = idx; i >= 1; i--) {
        int k = 1;
        for (auto e : gc[i]) {
            e = (e % 2 == 0 ? e-1 : e+1);
            if (val[e] != -1) { k = !val[e]; break; }
        }
        for (auto &e : gc[i]) val[e] = k;
    }
    for (int i = 1; i <= 2*n; i+=2) cout << (val[i] ? '+' : '-') << ' ';
    cout << '\n';
}