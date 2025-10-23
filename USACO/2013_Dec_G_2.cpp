/*
    author  : PakinDioxide
    created : 21/05/2025 21:06
    task    : 2013_Dec_G_2
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 5e4+5;

struct T {
    ll uLuR, xLuR, uLxR, xLxR, M;
    T operator+(const T &o) {
        ll nuLuR, nxLuR, nuLxR, nxLxR, nM;
        nuLuR = max({uLuR+o.xLuR, uLxR+o.uLuR, uLxR+o.xLuR});
        nxLuR = max({xLuR+o.xLuR, xLxR+o.uLuR, xLxR+o.xLuR});
        nuLxR = max({uLuR+o.xLxR, uLxR+o.uLxR, uLxR+o.xLxR});
        nxLxR = max({xLuR+o.xLxR, xLxR+o.uLxR, xLxR+o.xLxR});
        nM = max({nuLuR, nxLuR, nuLxR, nxLxR});
        return T{nuLuR, nxLuR, nuLxR, nxLxR, nM};
    }
};

int n, q;
ll s = 0;
T seg[4*mxN];

void upd(int l, int r, int idx, ll x, int node) {
    if (l == r) seg[node] = T{x, 0, 0, 0, x};
    else {
        int mid = l + (r-l)/2;
        if (mid >= idx) upd(l, mid, idx, x, node<<1);
        else upd(mid+1, r, idx, x, node<<1|1);
        seg[node] = seg[node<<1] + seg[node<<1|1];
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("optmilk.in", "r", stdin);
    freopen("optmilk.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) { ll e; cin >> e; upd(1, n, i, e, 1); }
    while (q--) {
        int idx; ll e; cin >> idx >> e;
        upd(1, n, idx, e, 1);
        s += seg[1].M;
    }
    cout << s << '\n';
}