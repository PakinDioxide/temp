#include "marbletracks.h"
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e3+5;

ll N;
vector <int> adj[mxN], ans;
ll dis[mxN][mxN];
ll sz[mxN];

vector<int> observe(int n, int q, vector<int> v, vector <tuple<int, int, int>> queries) {
    N = n;
    ans.resize(q);
    for (int i = 0; i < N; i++) if (v[i] != i) adj[v[i]].emplace_back(i);
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) dis[i][j] = INT_MAX;
    for (int st = 0; st < N; st++) {
        int vis[N]; memset(vis, 0, sizeof(vis));
        int x = st, d = 0;
        while (!vis[x]) {
            vis[x] = 1;
            dis[st][x] = d;
            d++;
            x = v[x];
        }
        if (x == st) sz[x] = d;
    }
    for (int i = 0; i < q; i++) {
        auto &[u, l, r] = queries[i];
        if (sz[u] == 0) {
            for (int x = 0; x < N; x++) if (dis[x][u] != INT_MAX) {
                if (dis[x][u] >= l && dis[x][u] <= r) ans[i]++;
            }
        } else {
            for (int x = 0; x < N; x++) if (dis[x][u] != INT_MAX) {
                if (dis[x][u] > r) continue;
                if (dis[x][u] >= l || (ceil((long double) (l - dis[x][u]) / sz[u])) * sz[u] <= r - dis[x][u]) ans[i]++;
            }
        }
    }
    return ans;
}

/*
r >= x + k*mod >= l
r-x >= k*mod >= l-x

k >= (l-x)/mod


*/
