/*
    author  : PakinDioxide
    created : 
    task    : 
*/
#include <bits/stdc++.h>
#define ll long long
#define db double
#define ld long double

using namespace std;

// BRUTE FORCE

const int mxN = 1e5+5;

int n, m, q, par[mxN], maxx = INT_MIN, ans[mxN];
vector <tuple <int, int, int>> E;
vector <pair <int, int>> Q;

int fi(int x) { if (x == par[x]) return x; return par[x] = fi(par[x]); }

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> q;
    E.resize(m);
    Q.resize(q);
    for (auto &[w, u, v] : E) cin >> u >> v >> w;
    for (auto &[x, y] : Q) cin >> x >> y, maxx = max(x, maxx);
    if (maxx > 1) {
        for (auto &[x, y] : Q) {
            int c = n;
            iota(par, par+n, 0);
            for (auto &[w, u, v] : E) if (x <= w && w <= y && fi(u) != fi(v)) par[fi(u)] = fi(v), c--;
            cout << c << '\n';
        }
        return 0;
    }
    int c = n;
    iota(par, par+n, 0);
    for (int i = 0; i < q; i++) E.emplace_back(Q[i].second, INT_MAX, i);
    sort(E.begin(), E.end());
    for (auto &[w, u, v] : E) {
        if (u == INT_MAX) ans[v] = c;
        else if (fi(u) != fi(v)) par[fi(u)] = fi(v), c--;
    }
    for (int i = 0; i < q; i++) cout << ans[i] << '\n';
    cout << '\n';
}

