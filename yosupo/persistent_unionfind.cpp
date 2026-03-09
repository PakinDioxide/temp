#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;

int par[mxN], sz[mxN], ans[mxN];
vector <int> adj[mxN];
vector <pair <int, int>> rpar, rsz;

int fi(int x) {
    if (x == par[x]) return x;
    else return fi(par[x]);
}

void mg(int u, int v) {
    u = fi(u), v = fi(v);
    if (sz[u] < sz[v]) swap(u, v);
    rsz.emplace_back(u, sz[u]);
    sz[u] += sz[v];
    rpar.emplace_back(v, par[v]);
    par[v] = u;
}

void rollback() {
    sz[rsz.back().first] = rsz.back().second; rsz.pop_back();
    par[rpar.back().first] = rpar.back().second; rpar.pop_back();
}

vector <pair <pair <int, int>, int>> QQ[mxN];
vector <tuple <int, int, int, int>> Q(mxN);

void dfs(int u) {
    for (auto &[x, idx] : QQ[u]) ans[idx] = (fi(x.first) == fi(x.second));
    for (auto v : adj[u]) {
        mg(get<2>(Q[v]), get<3>(Q[v]));
        dfs(v);
        rollback();
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) sz[i] = 1, par[i] = i;
    for (int i = 1; i <= q; i++) {
        auto &[t, k, u, v] = Q[i];
        cin >> t >> k >> u >> v; k++;
        ans[i] = -1;
        if (t == 1) QQ[k].emplace_back(make_pair (u, v), i);
        else adj[k].emplace_back(i);
    }
    dfs(0);
    for (int i = 1; i <= q; i++) if (ans[i] != -1) cout << ans[i] << '\n';
}