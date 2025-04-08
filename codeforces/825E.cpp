/*
    author  : PakinDioxide
    created : 07/04/2025 15:30
    task    : 825E
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int indeg[100005], ans[100005];
vector <int> adj[100005];
vector <int> topo;
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[v].emplace_back(u);
        indeg[u]++;
    }
    priority_queue <int> q;
    for (int i = 1; i <= n; i++) if (indeg[i] == 0) q.emplace(i);
    while (!q.empty()) {
        int u = q.top();
        q.pop();
        topo.emplace_back(u);
        for (auto v : adj[u]) if (--indeg[v] == 0) q.emplace(v);
    }
    reverse(topo.begin(), topo.end());
    for (int i = 0; i < n; i++) ans[topo[i]] = i+1;
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';
}