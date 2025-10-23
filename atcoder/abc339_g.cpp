#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MAX_BIT = 30;
const int mxN = 2e5+5;

int n, q;
vector <int> a;

struct Wavelet {
    vector <ll> p, pc;
    Wavelet *l, *r;
    void build(const vector <int> &A, int b) {
        if (b == 0 || A.empty()) return;
        l = new Wavelet();
        r = new Wavelet();
        ll c = 0, cc = 0;
        vector <int> L, R;
        for (auto &x : A) {
            if (x & (1 << (b-1))) R.emplace_back(x);
            else L.emplace_back(x), c++, cc += x;
            p.emplace_back(c);
            pc.emplace_back(cc);
        }
        l->build(L, b-1);
        r->build(R, b-1);
    }
    ll qr(int l, int r, int k, int b) {
        if (b == 0 || p.empty()) return (pc.empty() ? 0 : pc.back());
        int pr = (r > 0 ? p[r-1] : 0);
        int pl = (l > 0 ? p[l-1] : 0);
        ll sr = (r > 0 ? pc[r-1] : 0);
        ll sl = (l > 0 ? pc[l-1] : 0);
        if (k & (1 << (b-1))) return sr - sl + this->r->qr(l-pl, r-pr, k, b-1);
        else return this->l->qr(pl, pr, k, b-1);
    }
};  

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n; a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    Wavelet *root = new Wavelet();
    root->build(a, MAX_BIT);
    ll R = 0; cin >> q;
    while (q--) {
        ll l, r, k; cin >> l >> r >> k;
        l ^= R, r ^= R, k ^= R;
        cout << (R = root->qr(l-1, r, k+1, MAX_BIT)) << '\n';
    }
}