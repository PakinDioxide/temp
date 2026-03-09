#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;

int n, sz[mxN], vt[mxN], st[mxN], en[mxN], it = 0, c[mxN], cnt[mxN], ans[mxN], curr = 0;
vector <int> cc, adj[mxN];

void dfs(int u, int p) {
    st[u] = ++it;
    vt[it] = u;
    for (auto v : adj[u]) if (v != p) dfs(v, u), sz[u] += sz[v];
    sz[u]++;
    en[u] = it;
}

void sack(int u, int p, int k) {
    int mx = -1, hv = -1;
    for (auto v : adj[u]) if (v != p) {
        if (sz[v] > mx) mx = sz[v], hv = v;
    }
    for (auto v : adj[u]) if (v != p && v != hv) sack(v, u, 0);
    if (hv > -1) sack(hv, u, 1);
    for (auto v : adj[u]) if (v != p && v != hv) {
        for (int i = st[v]; i <= en[v]; i++) {
            if (cnt[c[vt[i]]]++ == 0) curr++;
        }
    }
    if (cnt[c[u]]++ == 0) curr++;
    ans[u] = curr;
    if (!k) {
        for (int i = st[u]; i <= en[u]; i++) {
            if (--cnt[c[vt[i]]] == 0) curr--;
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> c[i], cc.emplace_back(c[i]);
    sort(cc.begin(), cc.end());
    for (int i = 1; i <= n; i++) c[i] = upper_bound(cc.begin(), cc.end(), c[i]) - cc.begin();
    for (int i = 1, u, v; i < n; i++) cin >> u >> v, adj[u].emplace_back(v), adj[v].emplace_back(u);
    dfs(1, 1);
    sack(1, 1, 1);
    for (int i = 1; i <= n; i++) cout << ans[i] << ' '; cout << '\n';
}
