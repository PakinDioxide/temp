#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll mod = 1e9+7;
const int mxN = 3e5+5;

int n, m, par[2*mxN], r[2*mxN], cnt;
pair <int, int> pv[2*mxN];
ll ans[mxN];

int fi(int x) {return (x == par[x] ? x : par[x] = fi(par[x]));}

ll poww(ll x, ll y) {
    if (y == 0) return 1;
    ll k = poww(x, y/2); k *= k, k %= mod;
    if (y % 2 == 1) k *= x, k %= mod;
    return k;
}

void merge(int u, int v, int t) {
    u = fi(u), v = fi(v);
    if (u == v) return;
    if (r[u] < r[v]) swap(u, v);
    if (r[u] == r[v]) r[u]++;
    cnt--;
    pv[v] = make_pair(u, t);
    par[v] = u;
}

int fpp(int x, int t) {
    if (pv[x].second <= t && pv[x].first != x) return fpp(pv[x].first, t);
    else return x;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    cnt = 2*n;
    iota(par, par+2*n+1, 0);
    for (int i = 1; i <= n; i++) pv[2*i] = make_pair(2*i, 0), pv[2*i+1] = make_pair(2*i+1, 0);
    for (int i = 1; i <= m; i++) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 1) merge(2*u, 2*v, i), merge(2*u+1, 2*v+1, i);
        else merge(2*u, 2*v+1, i), merge(2*u+1, 2*v, i);
        ans[i] = poww(2, cnt/2);
    }
    int L = 0, R = m, a = INT_MAX;
    while (L <= R) {
        int x = L + (R-L)/2;
        int ok = 1;
        for (int i = 1; i <= n; i++) ok = min(ok, (int) (fpp(2*i, x) != fpp(2*i+1, x)));
        if (!ok) a = x, R = x-1;
        else L = x+1;
    }
    for (int i = 1; i <= m; i++) cout << (a > i ? ans[i] : 0) << '\n';
}

/*
vp[i] = pair(par, time), last change
*/