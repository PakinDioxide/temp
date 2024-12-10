#include <bits/stdc++.h>

using namespace std;

int seg[1000000], n, q, a[1000000];

void build(int node, int l, int r) {
    if (l == r) {seg[node] = a[l]; return;}
    int mid = (l+r)/2;
    build(node*2+1, l, mid);
    build(node*2+2, mid+1, r);
    seg[node] = max(seg[node*2+1], seg[node*2+2]);
}

void upd(int node, int l, int r, int x, int y) {
    if (l == r) {seg[node] = y; return;}
    int mid = (l+r)/2;
    if (x <= mid) upd(node*2+1, l, mid, x, y);
    else upd(node*2+2, mid+1, r, x, y);
    seg[node] = max(seg[node*2+1], seg[node*2+2]);
}

int qr(int node, int l, int r, int x) {
    if (l == r) {if (a[l] >= x) return l; else return 0;}
    int mid = (l+r)/2;
    if (x <= seg[node*2+1]) return qr(node*2+1, l, mid, x);
    else if (x <= seg[node*2+2]) return qr(node*2+2, mid+1, r, x);
    else return 0;
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    build(0, 1, n);
    while (q--) {
        int x;
        scanf("%d", &x);
        int idx = qr(0, 1, n, x);
        printf("%d ", idx);
        if (idx > 0) {
            a[idx] -= x;
            upd(0, 1, n, idx, a[idx]);
        }
    }
}