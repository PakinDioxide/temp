#include "finallymeet.h"
#include <bits/stdc++.h>
#define ll long long

using namespace std;

long long count_init(int N, int M, vector<int> U, vector<int> V) {
    vector <int> adj[N];
    for (int i = 0; i < M; i++) adj[U[i]].emplace_back(V[i]), adj[V[i]].emplace_back(U[i]);
    int dis[N][2]; memset(dis, 0, sizeof(dis));
    ll ANS = 0;
    for (int S = 0; S < N; S++) if (!dis[S][0] && !dis[S][1]) {
        set <int> ST;
        queue <pair <int, int>> q;
        q.emplace(S, 0);
        dis[S][0] = 1;
        while (!q.empty()) {
            auto [u, t] = q.front(); q.pop();
            ST.emplace(u);
            t ^= 1;
            for (auto v : adj[u]) if (!dis[v][t]) {
                dis[v][t] = 1;
                q.emplace(v, t);
            }
        }
        ll O = 0, E = 0, OE = 0;
        for (int i : ST) E += dis[i][0], O += dis[i][1], OE += (dis[i][0] & dis[i][1]);
        ANS += O * O + E * E - OE * OE;
    }
    return ANS;
}
