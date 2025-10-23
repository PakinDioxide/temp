/*
    author  : PakinDioxide
    created : 30/03/2025 22:14
    task    : 1190
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

tuple <ll, ll, ll, ll> seg[2000005];

void upd(int l, int r, int idx, ll x, int node) {
    if (l == r) seg[node] = {max(0LL, x), max(0LL, x), max(0LL, x), x};
    else {
        int mid = l + (r-l)/2;
        if (mid >= idx) upd(l, mid, idx, x, node*2+1);
        else upd(mid+1, r, idx, x, node*2+2);
        auto [mxa, sla, sra, sa] = seg[node*2+1];
        auto [mxb, slb, srb, sb] = seg[node*2+2];
        ll sl = max({sla, sa + slb, sa+sb}), sr = max({srb, sb + sra, sa+sb}), s = sa+sb;
        seg[node] = {max({sl, sr, mxa, mxb, sra + slb, 0LL}), sl, sr, s};
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        upd(1, n, i, x, 0);
    }
    while (q--) {
        int idx; ll x;
        cin >> idx >> x;
        upd(1, n, idx, x, 0);
        cout << get<0>(seg[0]) << '\n';
    }
}

/*
seg = max sum, max sum from left, max sum from right, sum
1 -2 1 5 -1
*/