/*
    author  : PakinDioxide
    created : 24/04/2025 20:12
    task    : o64_feb_c1_cheat
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;

int par[mxN], rnk[mxN], T = 0;
pair <int, int> vp[mxN];

int fi(int x) { return (x == par[x] ? x : par[x] = fi(par[x])); }

int fp(int x, int t) { return (vp[x].second <= t && vp[x].first != x ? fp(vp[x].first, t) : x); }

void cheat(int u, int v) {
    if (T == 0) for (int i = 1; i <= 200000; i++) par[i] = i, vp[i] = make_pair(i, 0);
    ++T;
    u = fi(u), v = fi(v);
    if (u == v) return;
    if (rnk[u] < rnk[v]) swap(u, v);
    if (rnk[u] == rnk[v]) rnk[u]++;
    vp[v] = make_pair(u, T);
    par[v] = u;
}

int investigate(int u, int v) {
    if (T == 0) for (int i = 1; i <= 200000; i++) par[i] = i, vp[i] = make_pair(i, 0);
    int l = 0, r = T, ans = -1;
    while (l <= r) {
        int t = l + (r-l)/2;
        if (fp(u, t) == fp(v, t)) r = t-1, ans = t;
        else l = t+1;
    }
    return ans;
}