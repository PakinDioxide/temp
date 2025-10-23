#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;
const int MAX_BIT = 30;

int n, q;
vector <int> a;

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
        if (b == 0) return 0;
        int pr = (r > 0 ? p[r-1] : 0);
        int pl = (l > 0 ? p[l-1] : 0);
        int cnt = pr - pl;
        if (k < cnt) return this->l->qr(pl, pr, k, b-1);
        else return (1 << (b-1)) + this->r->qr(l-pl, r-pr, k-cnt, b-1);
    }
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q; a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    Wavelet *root = new Wavelet();
    root->build(a, MAX_BIT);
    while (q--) {
        int l, r, k; cin >> l >> r >> k;
        cout << root->qr(l, r, k, MAX_BIT) << '\n';
    }
}