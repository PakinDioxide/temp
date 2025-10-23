/*
    author  : PakinDioxide
    created : 06/04/2025 21:13
    task    : 2020_Opn_G_2
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("fcolor.in", "r", stdin);
    freopen("fcolor.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector <int> adj[n+1];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[v].emplace_back(u);
    }
    int par[n+1];
    iota(par, par+n+1, 0);
    function <int(int)> fi = [&] (int x) {
        // cout << " fi " << x << '\n';
        if (x != par[x]) return par[x] = fi(par[x]);
        return x;
    };
    queue <int> q;
    for (int i = 1; i <= n; i++) q.emplace(i);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u != fi(u)) continue;
        vector <int> V;
        for (auto v : adj[u]) V.emplace_back(v);
        if (V.size() < 2) continue;
        int ok = 0;
        for (int i = 1; i < V.size(); i++) {
            if (fi(V[i]) == fi(V[0])) continue;
            par[fi(V[i])] = fi(V[0]), ok = 1;
            for (auto &e : adj[V[i]]) adj[fi(V[0])].emplace_back(e);
        }
        if (ok) q.emplace(fi(V[0]));
    }
    int idx = 1;
    map <int, int> k;
    for (int i = 1; i <= n; i++) {
        if (k[fi(i)] == 0) k[fi(i)] = idx++;
        cout << k[fi(i)] << '\n';
    }
}

/*

# iteration 1
1 = 4 = a
2 = 6 = b
3 = 9 = c

# iteration 2
7 = 3 = 9 = c
8 = 2 = 6 = b
1 = 4 = a

# iteration 3
7 = 3 = 9 = c
8 = 2 = 6 = b
1 = 4 = 5 = a

if (u, v) point at same connected component = merge(u, v)

*/