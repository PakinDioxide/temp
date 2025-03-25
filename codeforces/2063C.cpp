/*
    author  : PakinDioxide
    created : 11/03/2025 16:18
    task    : 
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector <int> adj[n+1];
    int deg[n+1];
    memset(deg, 0, sizeof(deg));
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++, deg[v]++;
    }
    multiset <int> ms;
    for (int i = 1; i <= n; i++) ms.insert(deg[i]);
    int ans = -1;
    for (int i = 1; i <= n; i++) {
        int sum = deg[i];
        ms.erase(ms.find(deg[i]));
        for (int v : adj[i]) {
            ms.erase(ms.find(deg[v]));
            ms.insert(deg[v]-1);
        }
        sum += *ms.rbegin() - 1;
        for (int v : adj[i]) {
            ms.erase(ms.find(deg[v]-1));
            ms.insert(deg[v]);
        }
        ms.insert(deg[i]);
        ans = max(ans, sum);
    }
    cout << ans << '\n';    
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}