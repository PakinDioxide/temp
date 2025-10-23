/*
    author  : 
    created : 26/08/2025 20:32
    task    : abc340_g
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5, mxK = 20;
const ll mod = 998244353;

int n, it = 0, df[mxN], C[mxN], dep[mxN], up[mxK][mxN];
vector <int> adj[mxN], gc[mxN], aux[mxN];
ll ans = 0;

void dfs(int u, int p) {
    df[u] = ++it;
    for (auto v : adj[u]) if (v != p) dep[v] = dep[u]+1, up[0][v] = u, dfs(v, u);
}

int LCA(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    int k = dep[x] - dep[y];
    for (int i = 0; i < mxK; i++) if (k & (1 << i)) x = up[i][x];
    if (x == y) return x;
    for (int i = mxK-1; i >= 0; i--) if (up[i][x] != up[i][y]) x = up[i][x], y = up[i][y];
    return up[0][x];
}

bool cmp(int x, int y) {
    return df[x] < df[y];
}

void build(int co) {
    vector <int> a;
    gc[co].emplace_back(1);
    sort(gc[co].begin(), gc[co].end(), cmp);
    gc[co].resize(unique(gc[co].begin(), gc[co].end()) - gc[co].begin());
    for (int i = 0; i < (int) gc[co].size()-1; i++) a.emplace_back(gc[co][i]), a.emplace_back(LCA(gc[co][i], gc[co][i+1]));
    a.emplace_back(gc[co].back());
    sort(a.begin(), a.end(), cmp);
    a.resize(unique(a.begin(), a.end()) - a.begin());
    for (int i = 0; i < (int) a.size()-1; i++) aux[LCA(a[i], a[i+1])].emplace_back(a[i+1]);
}

ll calc(int u, int co) {
    ll val = 1, s = 0;
    for (auto v : aux[u]) {
        ll k = calc(v, co);
        val = (val * k) % mod;
        s += k-1, s %= mod;
    }
    if (C[u] == co) val++, ans += (val-1+mod) % mod, ans %= mod;
    else ans += (val-1-s+mod)%mod, ans %= mod;
    aux[u].clear();
    return val;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> C[i], gc[C[i]].emplace_back(i);
    for (int i = 1, u, v; i < n; i++) cin >> u >> v, adj[u].emplace_back(v), adj[v].emplace_back(u);
    dfs(1, 1);
    for (int c = 1; c < mxK; c++) for (int i = 1; i <= n; i++) up[c][i] = up[c-1][up[c-1][i]];
    for (int i = 1; i <= n; i++) {
        build(i);
        int T = ans;
        calc(1, i);
    }
    cout << ans << '\n';
}