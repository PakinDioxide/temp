/*
    author  : 
    created : 10/08/2025 21:47
    task    : 2131D
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;
vector <int> adj[mxN];
int co[mxN];

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) adj[i].clear(), co[i] = 0;
    for (int i = 1; i < n; i++) { int u, v; cin >> u >> v; adj[u].emplace_back(v), adj[v].emplace_back(u); }
    int cnt = 0; for (int i = 1; i <= n; i++) if (adj[i].size() == 1) cnt++;
    for (int i = 1; i <= n; i++) for (auto v : adj[i]) co[i] += (adj[v].size() == 1);
    int mn = INT_MAX;
    for (int i = 1; i <= n; i++) mn = min(mn, cnt-co[i]-(adj[i].size()==1));
    cout << mn << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}