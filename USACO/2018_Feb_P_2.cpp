#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;

int q, it = 0, dep[mxN], up[30][mxN], id[mxN], mx[mxN], idx = 0;
pair <int, int> d[mxN];
vector <int> adj[mxN];

int LCA(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    int k = dep[u] - dep[v];
    for (int i = 0; i < 30; i++) if (k & (1 << i)) u = up[i][u];
    if (u == v) return u;
    for (int i = 29; i >= 0; i--) if (up[i][u] != up[i][v]) u = up[i][u], v = up[i][v];
    return up[0][u];
}

int dis(int u, int v) {
    int lca = LCA(u, v);
    return dep[u] + dep[v] - 2*dep[lca];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("newbarn.in", "r", stdin);
    freopen("newbarn.out", "w", stdout);
    cin >> q;
    while (q--) {
        char c; cin >> c;
        if (c == 'B') {
            int x; cin >> x;
            it++;
            if (x > -1) {
                id[it] = id[x];
                dep[it] = dep[x] + 1, up[0][it] = x;
                for (int c = 1; c < 30; c++) up[c][it] = up[c-1][up[c-1][it]];
                auto &[L, R] = d[id[it]];
                int P = dis(it, L), Q = dis(it, R);
                if (P >= Q && P > mx[id[it]]) mx[id[it]] = P, R = it;
                else if (Q >= P && Q > mx[id[it]]) mx[id[it]] = Q, L = it;
            } else {
                id[it] = ++idx;
                d[idx] = make_pair(it, it);
            }
        } else {
            int x; cin >> x;
            // cout << L << ' ' << R << '\n';
            auto &[L, R] = d[id[x]];
            cout << max(dis(x, L), dis(x, R)) << '\n';
        }
    }
}

/*
max dist from node will end at an end of the diameter
*/