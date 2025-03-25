/*
    author  : PakinDioxide
    created : 25/03/2025 19:46
    task    : calculator2
*/
#include <bits/stdc++.h>
#define ll long long
#define int long long

using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;
    map <int, int> vis;
    queue <pair <int, int>> q;
    q.emplace(0, x);
    while (!q.empty()) {
        auto [c, u] = q.front();
        q.pop();
        if (u == y) {cout << c << '\n'; return;}
        if (vis[u]) continue;
        vis[u] = 1;
        if (u < y) q.emplace(c+1, 3*u);
        if (u < y) q.emplace(c+1, 5*u);
        q.emplace(c+1, u+1);
        q.emplace(c+1, u-2);
    }
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}