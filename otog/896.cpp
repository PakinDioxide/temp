#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 100005;

int n, m, q, par[2*mxN];
vector <pair <int, int>> adj[mxN];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v, (u < v));
        adj[v].emplace_back(u, (v < u));
    }
    iota(par, par+2*n+2, 0);
    function <int(int)> fi = [&](int x) {
        if (x != par[x]) return par[x] = fi(par[x]);
        return x;
    };
    for (int i = 1; i <= n; i++) {
        vector <int> V[2];
        for (auto &[j, w] : adj[i]) V[w].emplace_back(j);
        for (int x = 0; x < 2; x++) {
            int u = 2*i+x;
            for (auto j : V[x]) {
                int v = 2*j+(!x);
                par[fi(v)] = fi(u);
            }
        }
    }
    map <int, unordered_set <int>> v;
    map <pair <int, int>, int> cnt;
    for (int i = 1; i <= n; i++) v[fi(2*i)].emplace(i), v[fi(2*i+1)].emplace(i), cnt[{min(fi(2*i), fi(2*i+1)), max(fi(2*i), fi(2*i+1))}]++;
    while (q--) {
        int x;
        cin >> x;
        if (fi(2*x) == fi(2*x+1)) cout << v[fi(2*x)].size() - 1 << '\n';
        else cout << v[fi(2*x)].size() + v[fi(2*x+1)].size() - cnt[{min(fi(2*x), fi(2*x+1)), max(fi(2*x), fi(2*x+1))}] - 1 << '\n';
    }
}