/*
    author  : PakinDioxide
    created : 19/05/2025 20:58
    task    : 1190
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;

struct T {
    ll L = 0, R = 0, M = 0, S = 0;
};

int n, q;
ll a[mxN];
T seg[4*mxN];

void mg(int node) {
    seg[node].L = max(seg[node<<1].L, seg[node<<1].S + seg[node<<1|1].L);
    seg[node].R = max(seg[node<<1|1].R, seg[node<<1|1].S + seg[node<<1].R);
    seg[node].M = max({seg[node].L, seg[node].R, seg[node<<1].M, seg[node<<1|1].M, seg[node<<1].R + seg[node<<1|1].L});
    seg[node].S = seg[node<<1].S + seg[node<<1|1].S;
}

void upd(int l, int r, int idx, int node) {
    if (l == r) seg[node] = {a[l], a[l], max(0LL, a[l]), a[l]};
    else {
        int mid = l + (r-l)/2;
        if (mid >= idx) upd(l, mid, idx, node<<1);
        else upd(mid+1, r, idx, node<<1|1);
        mg(node);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i], upd(1, n, i, 1);
    while (q--) {
        int idx; ll x; cin >> idx >> x; a[idx] = x;
        upd(1, n, idx, 1);
        cout << seg[1].M << '\n';
    }
}