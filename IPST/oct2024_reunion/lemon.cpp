#include "reunion.h"
#include <bits/stdc++.h>
#define ll long long

using namespace std;

namespace lemon {

    const ll mxN = 2005;

    int n, m;
    vector <pair <ll, int>> adj[mxN];

    int C = -1;
    ll mn = LLONG_MAX;
    vector <int> P;

    ll dijk(int x) {
        priority_queue <pair <ll, int>> q;
        ll dis[mxN];
        for (int i = 0; i < n; i++) dis[i] = LLONG_MAX;
        dis[x] = 0; q.emplace(0, x);
        while (!q.empty()) {
            int u = q.top().second; q.pop();
            for (auto [v, w] : adj[u]) if (dis[v] > dis[u] + w) q.emplace(-(dis[v] = dis[u] + w), v);
        }
        ll mx = 0;
        for (int i = 0; i < n; i++) mx = max(mx, dis[i]);
        return mx;
    }

    void lemon_init(int N, int M, std::vector<int> U, std::vector<int> V, std::vector<int> W, int x) {
        n = N, m = M;
        for (int i = 0; i < m; i++) adj[U[i]].emplace_back(V[i], W[i]), adj[V[i]].emplace_back(U[i], W[i]);
        for (int i = 0; i < n; i++) {
            ll k = dijk(i);
            if (k < mn) C = i, mn = k;
        }
        priority_queue <pair <ll, int>> q;
        ll dis[mxN], par[mxN];
        for (int i = 0; i < n; i++) dis[i] = LLONG_MAX;
        dis[C] = 0; q.emplace(0, C); par[C] = -1;
        while (!q.empty()) {
            int u = q.top().second; q.pop();
            for (auto [v, w] : adj[u]) if (dis[v] > dis[u] + w) par[v] = u, q.emplace(-(dis[v] = dis[u] + w), v);
        }
        x = par[x];
        while (x != -1) P.emplace_back(x), x = par[x];
    }

    int it = 0;

    int lemon_move(int u) {
        if (it == P.size()) return u;
        else return P[it++];
    }

}

/*
7 7
0 1 5
1 2 1
5 1 10
5 6 10
3 5 3
2 3 50
3 4 15
0 2
*/