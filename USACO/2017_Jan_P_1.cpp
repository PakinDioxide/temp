#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;

ll a[mxN], fen[mxN], ans[mxN];
int n, sz[mxN], vt[mxN], st[mxN], en[mxN], it = 0;
vector <int> adj[mxN];

void upd(int idx, ll x) { for (int i = idx; i <= n; i += i & -i) fen[i] += x; }
ll qr(int idx) { ll x = 0; for (int i = idx; i > 0; i -= i & -i) x += fen[i]; return x; }

void dfs1(int u) {
    sz[u] = 1;
    st[u] = ++it;
    vt[it] = u;
    for (auto v : adj[u]) dfs1(v), sz[u] += sz[v];
    en[u] = it;
}

void dfs2(int u, bool kp) {
    int mx = -1, idx = -1;
    for (auto v : adj[u]) {
        if (sz[v] > mx) mx = sz[v], idx = v;
    }
    for (auto v : adj[u]) if (v != idx) dfs2(v, 0);
    if (idx > -1) dfs2(idx, 1);
    for (auto v : adj[u]) if (v != idx) for (int i = st[v]; i <= en[v]; i++) upd(a[vt[i]], 1);
    upd(a[u], 1);
    ans[u] = qr(n) - qr(a[u]);
    if (!kp) for (int i = st[u]; i <= en[u]; i++) upd(a[vt[i]], -1);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);
    cin >> n;
    vector <ll> cc;
    for (int i = 1; i <= n; i++) cin >> a[i], cc.emplace_back(a[i]);
    sort(cc.begin(), cc.end());
    for (int i = 1; i <= n; i++) a[i] = upper_bound(cc.begin(), cc.end(), a[i]) - cc.begin(); //, cerr << a[i] << ' '; cerr << '\n';
    for (int i = 2, x; i <= n; i++) cin >> x, adj[x].emplace_back(i);
    dfs1(1);
    dfs2(1, 1);
    for (int i = 1; i <= n; i++) cout << ans[i] << '\n';
}

