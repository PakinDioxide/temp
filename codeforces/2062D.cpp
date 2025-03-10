#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll l[200005], r[200005];
vector <int> adj[200005];

void

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> l[i] >> r[i], adj[i].clear();
    for (int i = 1; i < n; i++) {int u, v; cin >> u >> v; adj[u].push_back(v), adj[v].push_back(u);}

}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}