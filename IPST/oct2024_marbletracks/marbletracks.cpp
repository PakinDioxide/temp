#include "marbletracks.h"
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;

ll N;
vector <int> adj[mxN], ans;
vector <tuple <int, ll, ll>> Q[mxN];

int sz[mxN], st[mxN], en[mxN], vt[mxN], it = 0, dep[mxN], fen[mxN];

void upd(int idx, int x) { for (int i = idx; i <= N; i += i & -i) fen[i] += x; }
int qr(int idx) { int x = 0; for (int i = idx; i > 0; i -= i & -i) x += fen[i]; return x; }

void dfs(int u) {
    st[u] = ++it;
    vt[it] = u;
    sz[u] = 1;
    for (auto v : adj[u]) dep[v] = dep[u] + 1, dfs(v), sz[u] += sz[v];
    en[u] = it;
}

void dfs2(int u, int kp) {
    int mx = -1, idx = -1;
    for (auto v : adj[u]) if (sz[v] > mx) {
        mx = sz[v];
        idx = v;
    }
    for (auto v : adj[u]) if (v != idx) {
        dfs2(v, 0);
    }
    if (idx != -1) dfs2(idx, 1);
    for (auto v : adj[u]) if (v != idx) {
        for (int i = st[v]; i <= en[v]; i++) upd(dep[vt[i]], 1);
    }
    upd(dep[u], 1);
    for (auto &[ii, l, r] : Q[u]) {
        l += dep[u] - 1, r += dep[u];
        if (u == 0) l = 0;
        ans[ii] = qr(min(N, r)) - qr(min(N, l));
    }
    if (kp) return;
    for (int i = st[u]; i <= en[u]; i++) upd(dep[vt[i]], -1);
}

vector<int> observe(int n, int q, vector<int> v, vector <tuple<int, int, int>> queries) {
    N = n;
    ans.resize(q);
    for (int i = 0; i < N; i++) if (v[i] != i) adj[v[i]].emplace_back(i);
    for (int i = 0; i < q; i++) {
        auto &[u, l, r] = queries[i];
        Q[u].emplace_back(i, l, r);
    }
    dep[0] = 1;
    dfs(0);
    dfs2(0, 1);
    return ans;
}
