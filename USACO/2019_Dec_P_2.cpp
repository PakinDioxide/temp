/*
    author  : PakinDioxide
    created : 10/04/2025 15:41
    task    : 2019_Dec_P_2
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;

int n, m, st[mxN], en[mxN], id = 0;
vector <int> adj[mxN];

void dfs(int u, int p) {
    st[u] = ++id;
    for (auto v : adj[u]) if (v != p) dfs(v, u);
    en[u] = id;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    // freopen("snowcow.in", "r", stdin);
    // freopen("snowcow.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    dfs(1, 1);

}

/*
    once we created the euler tour
    how can we answer each query?

    can we use segment tree?
    we can put the value in the set because it would cause MLE

    let consider a node u
    if u has color c
    then for all v in adj[u] will have c

    we should use fenwick ?
*/