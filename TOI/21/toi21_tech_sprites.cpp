/*
    author  : PakinDioxide
    created : 23/05/2025 00:42
    task    : toi21_tech_sprites
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e6+5;

int n, m, par[mxN], co[mxN], ans = 0;

int fi(int x) {
    if (x == par[x]) return x;
    else return par[x] = fi(par[x]);
}

struct T {
    ll a, b, idx;
    bool operator<(const T &o) {
        return (a < o.a ? 1 : a == o.a ? b < o.b : 0);
    }
};

T a[mxN];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    iota(par, par+n+1, 0);
    for (int i = 1; i <= n; i++) co[i] = 1, cin >> a[i].a >> a[i].b, a[i].idx = i;
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        if (fi(u) != fi(v)) co[fi(v)] += co[fi(u)], par[fi(u)] = fi(v);
    }
    sort(a+1, a+n+1);
    for (int i = 1; i <= n;) {
        int l = i, cnt = 0;
        while (cnt != co[fi(a[i].idx)]) {
            if (fi(a[l].idx) != fi(a[i].idx)) ans++, co[fi(a[i].idx)] += co[fi(a[l].idx)], par[fi(a[l].idx)] = fi(a[i].idx);
            cnt++, l++;
        }
        i = l;
    }
    cout << ans << '\n';
}