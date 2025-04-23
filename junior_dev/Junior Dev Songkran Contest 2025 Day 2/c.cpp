/*
    author  : PakinDioxide
    created : 14/04/2025 22:20
    task    : c
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 5e4+5;

int n, m, t, p;
ll base[mxN], vis[mxN];
vector <int> adj[mxN];
vector <ll> ans[mxN];

void dfs(int u) {
    for (auto v : adj[u]) {
        if (!vis[v]) dfs(v);
        for (auto &e : ans[v]) ans[u].emplace_back(e + base[u]);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> t >> p;
    for (int i = 1; i <= n; i++) cin >> base[i], vis[i] = 0;
    for (int i = 1; i <= m; i++) {
        int id, k;
        cin >> id >> k;
        for (int i = 0; i < k; i++) {
            int x;
            cin >> x;
            adj[id].emplace_back(x);
        }
        vis[id] = 1;
    }
    for (int i = 1; i <= n; i++) {if (!vis[i]) ans[i].emplace_back(base[i]); vis[i] = 0;}
    dfs(t);
    ll cnt = 0;
    for (auto &e : ans[t]) cnt += (e == p);//, cout << e << ' ';
    // cout << '\n';
    cout << cnt << '\n';
}