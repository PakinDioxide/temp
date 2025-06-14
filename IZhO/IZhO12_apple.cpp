/*
    author  : PakinDioxide
    created : 27/05/2025 23:38
    task    : IZhO12_apple
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e9+5;

struct T {
    int lz, val;
    T *u = nullptr, *v = nullptr;
    T() { val = lz = 0; }
    void add() {
        if (u == nullptr) u = new T();
        if (v == nullptr) v = new T();
    }
    void push(int v1, int v2) {
        if (lz) u->val = v1, u->lz = 1, v->val = v2, v->lz = 1, lz = 0;
    }
};

T *seg = new T();

void upd(int l, int r, int x, int y, T *g) {
    g->add();
    int mid = l + (r-l)/2;
    if (x <= l && r <= y) g->val = r-l+1, g->lz = 1, g->push(mid-l+1, r-mid);
    else {
        g->push(mid-l+1, r-mid);
        if (mid >= x) upd(l, mid, x, y, g->u);
        if (mid+1 <= y) upd(mid+1, r, x, y, g->v);
        g->val = g->u->val + g->v->val;
    }
}

int qr(int l, int r, int x, int y, T *g) {
    g->add();
    int mid = l + (r-l)/2;
    if (x <= l && r <= y) return g->val;
    else {
        g->push(mid-l+1, r-mid);
        int v = 0;
        if (mid >= x) v += qr(l, mid, x, y, g->u);
        if (mid+1 <= y) v += qr(mid+1, r, x, y, g->v);
        return v;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int q; cin >> q; int c = 0;
    while (q--) {
        int t, l, r; cin >> t >> l >> r;
        if (t == 1) cout << (c = qr(1, mxN, l+c, r+c, seg)) << '\n';
        else upd(1, mxN, l+c, r+c, seg);
    }
}