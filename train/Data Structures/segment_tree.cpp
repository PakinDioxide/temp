#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1000000;
int seg[N], val[N];

void recal(int node) {
    seg[node] = seg[node*2] + seg[node*2+1];
}

void build(int node, int l, int r) {
    if (l == r) seg[node] = val[l];
    else {
        int mid = (l+r)/2;
        build(node*2, l, mid);
        build(node*2+1, mid+1, r);
        recal(node);
    }
}

void upd(int node, int l, int r, int idx, int x) {
    if (l == r) seg[node] = x;
    else {
        int mid = (l+r)/2;
        if (mid >= idx) upd(node*2, l, mid, idx, x);
        else upd(node*2+1, mid+1, r, idx, x);
        recal(node);
    }
}

int sum(int node, int l, int r, int x, int y) {
    if (x <= l && r <= y) return seg[node];
    else {
        int mid = (l+r)/2, s = 0;
        if (mid >= x) s += sum(node*2, l, mid, x, y);
        if (mid+1 <= y) s += sum(node*2+1, mid+1, r, x, y);
        return s;
    }
}

int32_t main() {
    int n, q;
    scanf("%lld %lld", &n, &q);
    for (int i = 1; i <= n; i++) scanf("%lld", &val[i]);
    build(1, 1, n);
    while (q--) {
        int k, a, b;
        scanf("%lld %lld %lld", &k, &a, &b);
        if (k == 1) upd(1, 1, n, a, b);
        else printf("%lld\n", sum(1, 1, n, a, b));
    }
}