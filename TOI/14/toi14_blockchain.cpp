#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t, q;
    cin >> t >> q;
    map <set <pair <int, int>>, int> memo;
    while (t--) {
        int m;
        cin >> m;
        set <pair <int, int>> adj;
        for (int i = 0; i < m-1; i++) {
            int u, v;
            cin >> u >> v;
            adj.emplace(min(u, v), max(u, v));
        }
        memo[adj]++;
    }
    while (q--) {
        int m;
        cin >> m;
        set <pair <int, int>> adj;
        for (int i = 0; i < m-1; i++) {
            int u, v;
            cin >> u >> v;
            adj.emplace(min(u, v), max(u, v));
        }
        cout << memo[adj] << '\n';
    }
}