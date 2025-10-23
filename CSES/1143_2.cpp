/*
    author  : PakinDioxide
    created : 18/05/2025 20:53
    task    : 1143_2
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;

int n, q;

ll seg[4*mxN], a[mxN];

void build(int l, int r, int node) {
    if (l == r) seg[node] = a[l];
    else {
        int mid = l + (r-l)/2;
        build(l, mid, node*2+1);
        build(mid+1, r, node*2+2);
        seg[node] = max(seg[node*2+1], seg[node*2+2]);
    }
}

int qr(int l, int r, ll x, int node) {
    if (seg[node] < x) return 0;
    else if (l == r) return seg[node] -= x, l;
    else {
        int mid = l + (r-l)/2, k = 0;
        if (seg[node*2+1] >= x) k = qr(l, mid, x, node*2+1);
        else k = qr(mid+1, r, x, node*2+2);
        return seg[node] = max(seg[node*2+1], seg[node*2+2]), k;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, n, 0);
    while (q--) {
        ll x; cin >> x;
        cout << qr(1, n, x, 0) << ' ';
    }
    cout << '\n';
}