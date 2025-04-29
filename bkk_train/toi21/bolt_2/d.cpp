/*
    author  : PakinDioxide
    created : 27/04/2025 13:30
    task    : d
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;

ll a[mxN];
int fen[2][mxN];

void upd(int x, int idx, int k) {
    for (int i = idx; i < mxN; i += i & -i) fen[k][i] = max(fen[k][i], x);
}
int qry(int idx, int k) {
    int x = 0;
    for (int i = idx; i > 0; i -= i & -i) x = max(x, fen[k][i]);
    return x;
}
// int seg[2][4*mxN];

// void build(int l, int r, int node, int k) {
//     if (l == r) seg[k][node] = 0;
//     else {
//         int mid = l + (r-l)/2;
//         build(l, mid, node*2+1, k);
//         build(mid+1, r, node*2+2, k);
//         seg[k][node] = 0;
//     }
// }

// void upd(int l, int r, int idx, int x, int node, int k) {
//     if (l == r) seg[k][node] = max(seg[k][node], x);
//     else {
//         int mid = l + (r-l)/2;
//         if (mid >= idx) upd(l, mid, idx, x, node*2+1, k);
//         else upd(mid+1, r, idx, x, node*2+2, k);
//         seg[k][node] = max(seg[k][node*2+1], seg[k][node*2+2]);
//     }
// }

// int qry(int l, int r, int x, int y, int node, int k) {
//     if (x <= l && r <= y) return seg[k][node];
//     else {
//         int mid = l + (r-l)/2;
//         int mx = 0;
//         if (mid >= x) mx = max(mx, qry(l, mid, x, y, node*2+1, k));
//         if (mid+1 <= y) mx = max(mx, qry(mid+1, r, x, y, node*2+2, k));
//         return mx;
//     }
// }

void solve() {
    int n;
    cin >> n;
    vector <ll> cmp;
    for (int i = 1; i <= n; i++) { ll x, y; cin >> x >> y; a[i] = x*y; cmp.emplace_back(a[i]); }
    sort(cmp.begin(), cmp.end());
    for (int i = 1; i <= n; i++) a[i] = upper_bound(cmp.begin(), cmp.end(), a[i]) - cmp.begin();
    int ans = 0;
    memset(fen, 0, sizeof(fen));
    // build(1, n, 0, 0), build(1, n, 0, 1);
    for (int i = 1; i <= n; i++) {
        int mxd = qry(n-a[i]+1, 0) + 1, mxu = qry(a[i], 1) + 1;
        // int mxd = qry(1, n, a[i], n, 0, 0) + 1, mxu = qry(1, n, 1, a[i], 0, 1) + 1;
        ans = max({ans, mxd, mxu});
        upd(mxd, a[i], 1), upd(mxu, n-a[i]+1, 0);
        // upd(1, n, a[i], mxd, 0, 1), upd(1, n, a[i], mxu, 0, 0);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}

/*
au*bu > av*bv : go down left
au*bu < av*bv : go up left
*/