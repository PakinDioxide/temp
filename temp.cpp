/*
    author  : 
    created : 30/08/2025 14:43
    task    : temp
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5, mxK = 25;

int n, dep[mxN], df[mxN], up[mxK][mxN], it = 0;
ll A[mxN], seg[2*mxN];
vector <int> adj[mxN], D[mxN], aux[mxN];

void upd(int idx, ll x) {
    idx += n;
    seg[idx] = x;
    for (idx/=2; idx; idx/=2) seg[idx] = min(seg[idx<<1], seg[idx<<1|1]);
}

ll qr(int l, int r) {
    l += n, r += n+1;
    ll mn = LLONG_MAX;
    while (l < r) {
        if (l & 1) mn = min(mn, seg[l++]);
        if (r & 1) mn = min(mn, seg[--r]);
        l /= 2, r /= 2;
    }
    return mn;
}

void dfs(int u, int p) {
    df[u] = ++it, up[0][u] = p;
    for (auto v : adj[u]) if (v != p) dep[v] = dep[u] + 1, dfs(v, u);
    D[dep[u]].emplace_back(u);
}

bool cmp(int x, int y) {
    return df[x] < df[y];
}

int LCA(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    int k = dep[x] - dep[y];
    for (int i = 0; i < mxK; i++) if (k & (1 << i)) x = up[i][x];
    if (x == y) return x;
    for (int i = mxK - 1; i >= 0; i--) if (up[i][x] != up[i][y]) x = up[i][x], y = up[i][y];
    return up[0][x];
}

void build(int t) {
    D[t].emplace_back(1);
    sort(D[t].begin(), D[t].end(), cmp);
    vector <int> H;
    for (int i = 0; i < D[t].size() - 1; i++) {
        H.emplace_back(D[t][i]);
        H.emplace_back(LCA(D[t][i], D[t][i+1]));
    }
    H.emplace_back(D[t].back());
    sort(H.begin(), H.end(), cmp);
    H.resize(unique(H.begin(), H.end()) - H.begin());
    for (int i = 0; i < H.size()-1; i++) aux[LCA(H[i], H[i+1])].emplace_back(H[i+1]);
}

ll calc(int u, int t) {
    ll s = (t == dep[u] ? qr(0, t) : 0);
    for (auto v : aux[u]) s += calc(v, t);
    s = min(s, qr(t - dep[u], t));
    aux[u].clear();
    return s;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) adj[i].clear(), D[i-1].clear(), df[i] = 0, dep[i] = 0; it = 0;
    for (int i = 0; i < n; i++) cin >> A[i], upd(i, A[i]);
    for (int i = 1, u, v; i < n; i++) cin >> u >> v, adj[u].emplace_back(v), adj[v].emplace_back(u);
    dfs(1, 1);
    for (int c = 1; c < mxK; c++) for (int i = 1; i <= n; i++) up[c][i] = up[c-1][up[c-1][i]];
    ll ans = 0;
    for (int i = 0; i < n; i++) if (D[i].size() > 0) build(i), ans += calc(1, i);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}