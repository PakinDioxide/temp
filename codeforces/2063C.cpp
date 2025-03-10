#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    int deg[n+1];
    set <int> adj[n+1];
    pair <int, int> V[n-1];
    memset(deg, 0, sizeof(deg));
    for (int i = 0; i < n-1; i++) {int u, v; cin >> u >> v; V[i] = {u, v}, adj[u].insert(v), adj[v].insert(u), deg[u]++, deg[v]++;}
    pair <int, int> a = {deg[1], 1}, b = {deg[2], 1};
    if (a.first < b.first) swap(a, b);
    for (int i = n; i >= 1; i--) {
        if (deg[i] > a.first) b = a, a = make_pair(deg[i], i);
        else if (deg[i] > b.first) b = make_pair(deg[i], i);
        else if (deg[i] == b.first && adj[a.second].find(i) == adj[a.second].end()) b = make_pair(deg[i], i);
    }
    int ans = n-2;
    for (auto [u, v] : V) ans -= !(u == a.second || u == b.second || v == a.second || v == b.second);
    cout << ans << '\n';
    // cout << a.second << ' ' << b.second << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}