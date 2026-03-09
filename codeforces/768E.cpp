#include <bits/stdc++.h>
#define ll long long

using namespace std;

map <pair <int, ll>, int> gd, vis;

int get_gd(int u, ll mk, int p) {
    for (int i = p; i >= u; i--) if (mk & (1LL << i)) mk ^= (1LL << i);
    if (vis[{u, mk}]) return gd[{u, mk}];
    int v[63]; memset(v, 0, sizeof(v));
    for (int i = u-1; i >= 0; i--) if (mk & (1LL << i)) v[get_gd(u-i-1, mk ^ (1LL << i), u)] = 1;
    for (int i = 0; i < 63; i++) if (!v[i]) {
        gd[{u, mk}] = i;
        vis[{u, mk}] = 1;
        return i;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    gd[{0, 0}] = 0;
    vis[{0, 0}] = 1;
    int grd[61];
    for (int i = 0; i <= 60; i++) grd[i] = get_gd(i, (1LL << i) - 1, 60);
    int xo = 0;
    while (n--) {
        int x; cin >> x;
        xo ^= grd[x];
    }
    if (xo == 0) cout << "YES\n";
    else cout << "NO\n";
}

