#include <bits/stdc++.h>

using namespace std;

int n, q, adj[200005], deg[200005], cyc[200005], cyci = 0, vis[200005], cycidx[200005], jump[32][200005], cycsz[200005], kki = 1, indeg[200005];


int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> adj[i], indeg[adj[i]]++, jump[0][i] = adj[i];
    for (int i = 1; i < 32; i++) for (int j = 1; j <= n; j++) jump[i][j] = jump[i-1][jump[i-1][j]];
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        cyci++;
        stack <int> cc, ccc;
        int k = i;
        while (!vis[k]) {
            cyc[k] = cyci;
            cc.push(k);
            vis[k] = 1;
            k = adj[k];
        }
        int cyct, idx = 1;
        if (cyc[k] == cyci) {
            cyct = cyci;
            while (cc.top() != k) ccc.push(cc.top()), cc.pop(), cycsz[cyct]++;
            cycsz[cyct]++;
            cc.pop();
        } else {
            cyct = cyc[k];
        }
        while (!ccc.empty()) cycidx[ccc.top()] = idx++, ccc.pop();
        while (!cc.empty()) {
            cycidx[cc.top()] = 0;
            cyc[cc.top()] = cyct;
            deg[cc.top()] = deg[k] + 1;
            k = cc.top();
            cc.pop();
        }
    }
    while (q--) {
        int u, v;
        cin >> u >> v;
        if (cyc[u] != cyc[v] || deg[v] > deg[u]) {cout << -1 << '\n'; continue;}
        if (deg[v] > 0) {
            int k = u, jj = deg[u] - deg[v];
            for (int i = 0; i < 32; i++) if (jj & (1 << i)) k = jump[i][k];
            if (k != v) {cout << -1 << '\n'; continue;}
        }
        int ans = deg[u] - deg[v] + (cycidx[v] - cycidx[u] < 0 ? cycidx[v] - cycidx[u] + cycsz[cyc[v]] : cycidx[v] - cycidx[u]);
        cout << ans << '\n';
    }
}