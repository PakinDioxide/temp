// DFS

// #include <bits/stdc++.h>

// using namespace std;

// int n, m, vis[100005], cnt = 0;
// vector <int> adj[100005];
// vector <int> ans;

// void dfs(int u) {
//     cnt++;
//     if (cnt > n) return;
//     for (int v : adj[u]) {
//         if (!vis[v]) dfs(v);
//     }
//     vis[u] = 1;
//     ans.push_back(u);
// }

// int main() {
//     cin >> n >> m;
//     while (m--) {
//         int u, v;
//         cin >> u >> v;
//         adj[v].push_back(u);
//     }
//     for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i);
//     if (cnt > n) cout << "IMPOSSIBLE";
//     else {
//         for (int i : ans) cout << i << ' ';
//     }
// }

// Kahn

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector <int> adj[n+1];
    int ind[n+1];
    for (int i = 1; i <= n; i++) ind[i] = 0;
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        ind[v]++;
    }
    queue <int> q;
    vector <int> ans;
    for (int i = 1; i <= n; i++) if (ind[i] == 0) q.push(i);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for (int v : adj[u]) {
            ind[v]--;
            if (ind[v] == 0) q.push(v);
        }
    }
    if (ans.size() < n) cout << "IMPOSSIBLE";
    else {
        for (int i : ans) cout << i << ' ';
    }
}