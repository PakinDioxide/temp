#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solvea() {
    int n, m; cin >> n >> m;
    vector <int> adj[n+1];
    for (int i = 0, u, v; i < m; i++) cin >> u >> v, adj[u].emplace_back(v),adj[v].emplace_back(u);
    queue <int> q;
    int dis[n+1]; for (int i = 1; i <= n; i++) dis[i] = INT_MAX;
    dis[1] = 0;
    q.emplace(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : adj[u]) if (dis[v] > dis[u] + 1) dis[v] = dis[u] + 1, q.emplace(v);
    }
    string s = "rgb";
    for (int i = 1; i <= n; i++) cout << s[dis[i] % 3];
    cout << '\n';
}

void solveb() {
    int q; cin >> q;
    while (q--) {
        int sz; cin >> sz;
        string s; cin >> s;
        map <char, int> vis;
        for (int i = 0; i < sz; i++) vis[s[i]] = i+1;
        char ms;
        if (!vis['r']) ms = 'r';
        else if (!vis['g']) ms = 'g';
        else ms = 'b';
        if ((vis['r'] > 0) + (vis['g'] > 0) + (vis['b'] > 0) == 1) {
            cout << 1 << '\n';
            continue;
        }
        if (ms == 'r') cout << vis['b'] << '\n';
        else if (ms == 'g') cout << vis['r'] << '\n';
        else cout << vis['g'] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string s; cin >> s;
    int t; cin >> t;
    if (s == "first") while (t--) solvea();
    else while (t--) solveb();
}

