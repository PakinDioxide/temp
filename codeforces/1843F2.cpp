/*
    author  : 
    created : 17/07/2025 00:02
    task    : 1843F2
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5, mxL = 20;

int Q, sz = 0, up[mxL][mxN], sum[mxL][mxN], dep[mxN], W[mxN];
pair <int, int> e[mxL][mxN], b[mxL][mxN], dp[mxL][mxN];

void solve() {
    sz = 0;
    cin >> Q;
    auto LCA = [&] (int x, int y) {
        if (dep[x] < dep[y]) swap(x, y);
        int k = dep[x] - dep[y];
        for (int i = 0; i < mxL; i++) if (k & (1 << i)) x = up[i][x];
        if (x == y) return x;
        for (int i = mxL-1; i >= 0; i--) if (up[i][x] != up[i][y]) x = up[i][x], y = up[i][y];
        return up[0][x];
    };
    auto add = [&] (int p, int w) {
        ++sz; int u = sz;
        W[u] = w;
        dep[u] = dep[p] + 1;
        up[0][u] = p, sum[0][u] = w;
        e[0][u] = b[0][u] = dp[0][u] = make_pair(w, w);
        for (int c = 1; c < mxL; c++) {
            up[c][u] = up[c-1][up[c-1][u]];
            e[c][u].first = max(e[c-1][up[c-1][u]].first, sum[c-1][up[c-1][u]] + e[c-1][u].first);
            e[c][u].second = min(e[c-1][up[c-1][u]].second, sum[c-1][up[c-1][u]] + e[c-1][u].second);
            b[c][u].first = max(b[c-1][u].first, sum[c-1][u] + b[c-1][up[c-1][u]].first);
            b[c][u].second = min(b[c-1][u].second, sum[c-1][u] + b[c-1][up[c-1][u]].second);
            dp[c][u].first = max({dp[c-1][u].first, dp[c-1][up[c-1][u]].first, e[c-1][u].first + b[c-1][up[c-1][u]].first});
            dp[c][u].second = min({dp[c-1][u].second, dp[c-1][up[c-1][u]].second, e[c-1][u].second + b[c-1][up[c-1][u]].second});
            sum[c][u] = sum[c-1][u] + sum[c-1][up[c-1][u]];
        }
    };
    add(0, 1);
    while (Q--) {
        char op; cin >> op;
        if (op == '+') {
            int p, w; cin >> p >> w;
            add(p, w);
        } else {
            int u, v, k; cin >> u >> v >> k;
            int lca = LCA(u, v);
            int mx = 0, mxu = 0, mxv = 0, mn = 0, mnu = 0, mnv = 0;
            int k1 = dep[u] - dep[lca] + 1, k2 = dep[v] - dep[lca] + 1;
            for (int c = 0; c < mxL; c++) {
                if (k1 & (1 << c)) {
                    mx = max({mx, dp[c][u].first, mxu + b[c][u].first});
                    mn = min({mn, dp[c][u].second, mnu + b[c][u].second});
                    mxu = max(mxu + sum[c][u], e[c][u].first);
                    mnu = min(mnu + sum[c][u], e[c][u].second);
                    u = up[c][u];
                }
                if (k2 & (1 << c)) {
                    mx = max({mx, dp[c][v].first, mxv + b[c][v].first});
                    mn = min({mn, dp[c][v].second, mnv + b[c][v].second});
                    mxv = max(mxv + sum[c][v], e[c][v].first);
                    mnv = min(mnv + sum[c][v], e[c][v].second);
                    v = up[c][v];
                }
            }
            mx = max(mx, mxu + mxv - W[lca]), mn = min(mn, mnu + mnv - W[lca]);
            if (k >= mn && k <= mx) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}