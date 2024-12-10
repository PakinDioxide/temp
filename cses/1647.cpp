#include <bits/stdc++.h>

using namespace std;

int seg[1000000], n, q, a[1000000];

void build(int node, int l, int r) {
    if (l == r) {seg[node] = a[l]; return;}
    int mid = (l+r)/2;
    build(node*2+1, l, mid);
    build(node*2+2, mid+1, r);
    seg[node] = min(seg[node*2+1], seg[node*2+2]);
}

void upd(int node, int l, int r, int x, int y) {
    if (l == r) {seg[node] = y; return;}
    int mid = (l+r)/2;
    if (x <= mid) upd(node*2+1, l, mid, x, y);
    else upd(node*2+2, mid+1, r, x, y);
    seg[node] = min(seg[node*2+1], seg[node*2+2]);
}

int qr(int node, int l, int r, int x, int y) {
    if (x <= l && r <= y) return seg[node];
    int ans = INT_MAX, mid = (l+r)/2;
    if (x <= mid) ans = min(ans, qr(node*2+1, l, mid, x, y));
    if (y > mid) ans = min(ans, qr(node*2+2, mid+1, r, x, y));
    return ans;
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    build(0, 1, n);
    while (q--) {
        int y, z;
        scanf("%d %d", &y, &z);
        printf("%d\n", qr(0, 1, n, y, z));
    }
}