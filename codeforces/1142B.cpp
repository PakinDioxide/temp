/*
    author  : 
    created : 14/07/2025 20:59
    task    : 1142B
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5, mxL = 20;

int n, m, q, p[mxN], a[mxN], idx[mxN], dp[mxL][mxN], bf[mxN], val[mxN], ans[mxN], seg[4*mxN];

void build(int l, int r, int u) {
    if (l == r) seg[u] = val[l];
    else {
        int mid = l + (r-l)/2;
        build(l, mid, u<<1);
        build(mid+1, r, u<<1|1);
        seg[u] = max(seg[u<<1], seg[u<<1|1]);
    }
}

int qr(int l, int r, int x, int y, int u) {
    if (x <= l && r <= y) return seg[u];
    else {
        int mid = l + (r-l)/2, mx = -1;
        if (mid >= x) mx = max(mx, qr(l, mid, x, y, u<<1));
        if (mid+1 <= y) mx = max(mx, qr(mid+1, r, x, y, u<<1|1));
        return mx;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) cin >> p[i], bf[p[i]] = p[i-1]; bf[p[1]] = p[n];
    for (int i = 1; i <= m; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) { dp[0][i] = idx[bf[a[i]]]; idx[a[i]] = i; }
    for (int c = 1; c < mxL; c++) for (int i = 1; i <= m; i++) dp[c][i] = dp[c-1][dp[c-1][i]];
    for (int i = 1; i <= m; i++) {
        val[i] = i;
        for (int c = 0; c < mxL; c++) if ((n-1) & (1 << c)) val[i] = dp[c][val[i]];
    }
    build(1, m, 1);
    while (q--) {
        int l, r; cin >> l >> r;
        cout << (l <= qr(1, m, l, r, 1));
    }
    cout << '\n';
}