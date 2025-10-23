#pragma once

struct Wavelet {
    vector <int> p;
    Wavelet *l, *r;
    void build(const vector <int> &A, int b) {
        if (b == 0 || A.empty()) return;
        l = new Wavelet();
        r = new Wavelet();
        int c = 0;
        vector <int> L, R;
        for (int x : A) {
            if (x & (1 << (b-1))) R.emplace_back(x);
            else L.emplace_back(x), c++;
            p.emplace_back(c);
        }
        l->build(L, b-1);
        r->build(R, b-1);
    }
    int qr(int l, int r, int k, int b) { // [l, r), 0-index
        if (b == 0 || p.empty()) return 0;
        int pr = (r > 0 ? p[r-1] : 0);
        int pl = (l > 0 ? p[l-1] : 0);
        int cnt = pr - pl;
        if (k < cnt) return this->l->qr(pl, pr, k, b-1);
        else return (1 << (b-1)) + this->r->qr(l-pl, r-pr, k-cnt, b-1);
    }
};
