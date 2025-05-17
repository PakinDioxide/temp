/*
    author  : PakinDioxide
    created : 11/05/2025 23:30
    task    : 2134
*/
#include <bits/stdc++.h>
#define ll long long

#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")

using namespace std;

const int mxN = 2e5+5;

int n, q, id[mxN], tp[mxN], sz[mxN], dep[mxN], par[mxN], a[mxN], seg[4*mxN];
vector <int> adj[mxN];

void upd(int idx, int x) {
    idx += n; seg[idx] = x; idx/=2;
    while (idx) seg[idx] = max(seg[idx*2], seg[idx*2+1]), idx/=2;
}
 
int qr(int x, int y) {
    int ml = 0, mr = 0;
    x += n, y += n+1;
    while (x < y) {
        if (x & 1) ml = max(ml, seg[x++]);
        if (y & 1) mr = max(mr, seg[--y]);
        x/=2, y/=2;
    }
    return max(ml, mr);
}
 
void dfs(int u, int p) {
    par[u] = p;
    for (auto v : adj[u]) if (v != p) dep[v] = dep[u]+1, dfs(v, u), sz[u] += sz[v];
    sz[u]++;
}
 
int it = 1;
 
void hld(int u, int p, int P) {
    id[u] = it++;
    tp[u] = P;
    upd(id[u], a[u]);
    int mx = 0, idx = -1;
    for (auto v : adj[u]) if (v != p) if (sz[v] > mx) mx = sz[v], idx = v;
    if (idx == -1) return;
    hld(idx, u, P);
    for (auto v : adj[u]) if (v != p && v != idx) hld(v, u, v);
}
 
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1, u, v; i < n; i++) cin >> u >> v, adj[u].emplace_back(v), adj[v].emplace_back(u);
    dfs(1, 1);
    hld(1, 1, 1);
    while (q--) {
        int t; cin >> t;
        if (t == 1) { int u; int x; cin >> u >> x; upd(id[u], x); a[u] = x; }
        else {
            int u, v; cin >> u >> v;
            int ans = 0;
            while (tp[u] != tp[v]) {
                if (dep[tp[u]] < dep[tp[v]]) swap(u, v);
                ans = max(ans, qr(id[tp[u]], id[u]));
                u = par[tp[u]];
            }
            if (dep[u] > dep[v]) swap(u, v);
            ans = max(ans, qr(id[u], id[v]));
            cout << ans << ' ';
        }
    }
    cout << '\n';
}