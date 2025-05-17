/*
    author  : PakinDioxide
    created : 03/05/2025 10:24
    task    : 2013_Feb_S_2
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 505;

pair <int, int> d[4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

int n, N, par[mxN*mxN], co[mxN*mxN], a[mxN][mxN];
vector <tuple <ll, int, int>> V;

int fi(int x) { return x == par[x] ? x : par[x] = fi(par[x]); }

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("tractor.in", "r", stdin);
    freopen("tractor.out", "w", stdout);
    cin >> n;
    N = n*n;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j], co[n*i+j] = 1;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) for (auto &[dx, dy] : d) {
        int nx = i + dx, ny = j + dy;
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        V.emplace_back(abs(a[i][j] - a[nx][ny]), n*i+j, n*nx+ny);
    }
    iota(par, par+n*n, 0);
    sort(V.begin(), V.end());
    for (auto &[w, u, v] : V) {
        if (fi(u) == fi(v)) continue;
        co[fi(u)] += co[fi(v)];
        par[fi(v)] = fi(u);
        if (co[fi(u)] >= ceil(n*n/2.0)) { cout << w << '\n'; return 0; }
    }
}