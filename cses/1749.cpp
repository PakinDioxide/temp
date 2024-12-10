#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, a[200005], seg[800005];

void build(int node, int l, int r) {
    if (l == r) seg[node] = 1;
    else {
        int mid = (l+r)/2;
        build(node*2+1, l, mid);
        build(node*2+2, mid+1, r);
        seg[node] = seg[node*2+1] + seg[node*2+2];
    }
}

void rm(int node, int l, int r, int x) {
    if (l == r) seg[node] = 0;
    else {
        int mid = (l+r)/2;
        if (x <= mid) rm(node*2+1, l, mid, x);
        else rm(node*2+2, mid+1, r, x);
        seg[node] = seg[node*2+1] + seg[node*2+2];
    }
}

int get(int node, int l, int r, int x, int cnt) {
    if (l == r) return l;
    else {
        int ll = seg[node*2+1], rr = seg[node*2+2], mid = (l+r)/2;
        if (ll + cnt >= x) return get(node*2+1, l, mid, x, cnt);
        else return get(node*2+2, mid+1, r, x, cnt + ll);
    }
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(0, 1, n);
    for (int i = 0; i < n; i++) {
        int q;
        cin >> q;
        int idx = get(0, 1, n, q, 0);
        cout << a[idx] << ' ';
        rm(0, 1, n, idx);
    }
}
