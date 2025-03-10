#include <bits/stdc++.h>

using namespace std;

int seg[400005];
set <int> val[100005];

void build(int l, int r, int node) {
    if (l == r) seg[node] = l, val[l].insert(l);
    else {
        int mid = (l+r)/2;
        build(l, mid, node*2+1);
        build(mid+1, r, node*2+2);
        seg[node] = max(seg[node*2+1], seg[node*2+2]);
    }
}

void upd(int l, int r, int idx, int k, int node) {
    if (l == idx) seg[node] = k;
    else {
        int mid = (l+r)/2;
        if (mid >= idx) upd(l, mid, idx, k, node*2+1);
        else upd(mid+1, r, idx, k, node*2+2);
        seg[node] = max(seg[node*2+1], seg[node*2+2]);
    }
}

int mx(int l, int r, int x, int y, int node) {
    if (x <= l && r <= y) return seg[node];
    else {
        int mid = (l+r)/2, k = 0;
        if (mid >= x) k = max(mx(l, mid, x, y, node*2+1), k);
        if (mid+1 <= y) k = max(mx(mid+1, r, x, y, node*2+2), k);
        return k;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q;
    cin >> n >> q;
    build(1, n, 0);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            val[x].insert(y);
            upd(1, n, x, *val[x].rbegin(), 0);
        } else if (t == 2) {
            int z, r;
            cin >> z;
            do {
                r = z;
                z = max(z, mx(1, n, 1, z, 0));
            } while (z != r);
            cout << z << '\n';
        } else {
            int x, y;
            cin >> x >> y;
            val[x].erase(val[x].find(y));
            val[x].insert(x);
            upd(1, n, x, *val[x].rbegin(), 0);
        }
    }
}