/*
    author  : PakinDioxide
    created : 15/04/2025 21:36
    task    : c_SUBTASK1
*/
#include <bits/stdc++.h>
#define ll long long
#define int ll

using namespace std;

ll n, q, c[2005], t[2005], need[2005], val[2005], dep[2005], idx[2005], par[2005];
vector <int> adj[2005], vis;
set <int> vis2;
vector <pair <int, int>> euler;

void dfs1(int u, int p) {
    par[u] = p;
    idx[u] = euler.size();
    euler.emplace_back(dep[u], u);
    for (auto v : adj[u]) {
        if (v == p) continue;
        dep[v] = dep[u] + 1;
        dfs1(v, u);
        euler.emplace_back(dep[u], u);
    }
}

void dfs(int u, int p, int k) {
    k = max(k, (int) need[u]);
    if (k) vis2.emplace(u);
    for (auto v : adj[u]) if (v != p) dfs(v, u, k);
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> t[i];
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    dfs1(1, 1);
    int nn = euler.size();
    pair <int, int> rmq[30][nn];
    for (int i = 0; i < nn; i++) rmq[0][i] = euler[i];
    for (int i = 1; i < 30; i++) for (int j = 0; j + (1 << i) < nn; j++) rmq[i][j] = min(rmq[i-1][j], rmq[i-1][j+(1<<(i-1))]);
    // for (int i = 0; i < nn; i++) cout << euler[i].second << ' ';
    // cout << '\n';
    while (q--) {
        int x;
        cin >> x;
        if (x == 1) {
            ll cnt, add, color;
            cin >> cnt;
            vis.clear();
            vis2.clear();
            ll l = INT_MAX, r = 0;
            vector <int> ask;
            for (int i = 0; i < cnt; i++) {
                int y;
                cin >> y;
                ask.emplace_back(y);
                l = min(l, idx[y]);
                r = max(r, idx[y]);
            }
            cin >> add >> color;
            r++;
            int d = r-l;
            int idx = l;
            pair <int, int> lca = {INT_MAX, INT_MAX};
            for (int i = 0; i < 30; i++) if (d & (1 << i)) lca = min(lca, rmq[i][idx]), idx += (1 << i);
            int visu[n+5];
            memset(visu, 0, sizeof(visu));
            for (auto u : ask) {
                while (!visu[u]) {
                    if (c[u] == color) val[u] = max(0LL, min(t[u], val[u] + add));
                    visu[u] = 1;
                    if (u == lca.second) break;
                    u = par[u];
                }
            }
        } else if (x == 2) {
            ll cnt, k, add, color;
            cin >> cnt >> k;
            vis.clear();
            vis2.clear();
            for (int i = 1; i <= n; i++) need[i] = 0;
            for (int i = 0; i < cnt; i++) {
                int y;
                cin >> y;
                need[y] = 1;
            }
            cin >> add >> color;
            dfs(k, k, 0);
            for (auto &e : vis2) {if (c[e] == color) val[e] = max(0LL, min(t[e], val[e] + add));}
        } else if (x == 3) {
            ll u, cng;
            cin >> u >> cng;
            t[u] = cng;
            val[u] = min(val[u], t[u]);
        } else {
            ll u, cng;
            cin >> u >> cng;
            c[u] = cng;
        }
    }
    for (int i = 1; i <= n; i++) cout << val[i] << ' ';
    cout << '\n';
}

/*
8 1
8 5 9 4 9 2 6 5
1 2 2 1 1 1 3 1
1 2
2 3
3 4
2 5
2 6
3 7
4 8

8 1
8 5 9 4 9 2 6 5
1 2 2 1 1 1 3 1
1 2
2 3
3 4
2 5
2 6
3 7
4 8
1
3
4 5 6
5 1
*/