/*
    author  : PakinDioxide
    created : 
    task    : 
*/
#include <bits/stdc++.h>
#define ll long long
#define db double
#define ld long double

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using pddd = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#pragma GCC optimize("O2")
#pragma GCC target("avx2")

const int mxN = 1e5+5;

struct T {
    int val;
    bool lz;
    vector <int> s;
    void rst(int sz) { s.resize(sz); val = lz = 0; }
    T operator+(const T &b) {
        T k; k.rst(0);
        int l = 0, r = 0;
        while (l < s.size() && r < b.s.size()) {
            if (s[l] <= b.s[r]) k.s.emplace_back(s[l++]);
            else k.s.emplace_back(b.s[r++]);
        }
        while (l < s.size()) k.s.emplace_back(s[l++]);
        while (r < b.s.size()) k.s.emplace_back(b.s[r++]);
        return k;
    }
};

int n, q, a[mxN], s2[4*mxN], lz[4*mxN], sms[20][mxN];
T s[4*mxN];

void puisfadhl(int g, int u, int v) {
    if (!lz[g]) return;
    s2[u] = s2[v] = s2[g];
    lz[u] = lz[v] = 1;
    lz[g] = 0;
}

void updkaflkjd(int l, int r, int x, int y, int k, int u) {
    if (x <= l && r <= y) s2[u] = k, lz[u] = 1;
    else {
        puisfadhl(u, u<<1, u<<1|1);
        int mid = l + (r-l)/2;
        if (mid >= x) updkaflkjd(l, mid, x, y, k, u<<1);
        if (mid+1 <= y) updkaflkjd(mid+1, r, x, y, k, u<<1|1);
    }
}

void buildkdafdkk(int l, int r, int u) {
    if (l == r) a[l] = s2[u];
    else {
        puisfadhl(u, u<<1, u<<1|1);
        int mid = l + (r-l)/2;
        buildkdafdkk(l, mid, u<<1);
        buildkdafdkk(mid+1, r, u<<1|1);
    }
}

void bd(int l, int r, int lv) {
    if (l == r) sms[lv][l] = a[l];
    else {
        int mid = l+(r-l)/2;
        bd(l, mid, lv+1);
        bd(mid+1, r, lv+1);
        int x = l, y = mid+1, it = l;
        while (x <= mid && y <= r) {
            if (sms[lv+1][x] <= sms[lv+1][y]) sms[lv][it++] = sms[lv+1][x++];
            else sms[lv][it++] = sms[lv+1][y++];
        }
        while (x <= mid) {
            sms[lv][it++] = sms[lv+1][x++];
        }
        while (y <= r) {
            sms[lv][it++] = sms[lv+1][y++];
        }
    }
}

vector <int> ans;

void mgg(int lv, int l, int r) {
    int x = 0, y = l, mid = ans.size()-1, it = 0;
    vector <int> ttt(ans.size() + (r-l+1));
        while (x <= mid && y <= r) {
            if (ans[x] <= sms[lv+1][y]) ttt[it++] = ans[x++];
            else ttt[it++] = sms[lv+1][y++];
        }
        while (x <= mid) {
            ttt[it++] = ans[x++];
        }
        while (y <= r) {
            ttt[it++] = sms[lv+1][y++];
        }
    ans = ttt;
}

void qry(int l, int r, int x, int y, int lv) {
    if (x <= l && r <= y) mgg(lv-1, l, r);
    else {
        int mid = l + (r-l)/2;
        if (mid >= x) qry(l, mid, x, y, lv+1);
        if (mid+1 <= y) qry(mid+1, r, x, y, lv+1);
    }
}


void push(int g, int u, int v) {
    if (!s[g].lz) return;
    for (auto &e : s[u].s) e = s[g].val;
    for (auto &e : s[v].s) e = s[g].val;
    s[u].val = s[v].val = s[g].val;
    s[u].lz = s[v].lz = 1;
    s[g].lz = 0;
}

void build(int l, int r, int u) {
    if (l == r) s[u].rst(1), s[u].s[0] = a[l];
    else {
        s[u].rst(r-l+1);
        int mid = l + (r-l)/2;
        build(l, mid, u<<1);
        build(mid+1, r, u<<1|1);
        s[u] = s[u<<1] + s[u<<1|1];
    }
}

void upd(int l, int r, int x, int y, int k, int u) {
    if (x <= l && r <= y) {
        for (auto &e : s[u].s) e = k;
        s[u].lz = 1;
        s[u].val = k;
        push(u, u<<1, u<<1|1);
    } else {
        push(u, u<<1, u<<1|1);
        int mid = l + (r-l)/2;
        if (mid >= x) upd(l, mid, x, y, k, u<<1);
        if (mid+1 <= y) upd(mid+1, r, x, y, k, u<<1|1);
        s[u] = s[u<<1] + s[u<<1|1];
    }
}

T qr(int l, int r, int x, int y, int u) {
    if (x <= l && r <= y) return s[u];
    else {
        push(u, u<<1, u<<1|1);
        int mid = l + (r-l)/2; T v; v.rst(0);
        if (mid >= x) v = v + qr(l, mid, x, y, u<<1);
        if (mid+1 <= y) v = v + qr(mid+1, r, x, y, u<<1|1);
        return v;
    }
}

vector <tuple <int, int, int, int, int>> Q;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    if (n <= 10000 && q <= 10000) {
        build(0, n-1, 1);
        // cout << "BUID ";
        // for (auto &e : s[1].s) cout << e << ' ';
        // cout << '\n';
        while (q--) {
            int t, l, r, k; cin >> t >> l >> r >> k;
            if (t == 1) upd(0, n-1, l, r, k, 1);
            else {
                cout << qr(0, n-1, l, r, 1).s[k-1] << '\n';
                // T k = qr(0, n-1, l, r, 1);
                // for (auto &e : k.s) cout << e << ' ';
                // cout << '\n';
            }
        }
        return 0;
    }
    int sqt = ceil(sqrt(n));
    for (int i = 0; i < q; i++) {
        int t, l, r, k; cin >> t >> l >> r >> k;
        if (t == 1) updkaflkjd(0, n-1, l, r, k, 1);
        else Q.emplace_back(l/sqt, r, l, k, i);
    }
    buildkdafdkk(0, n-1, 1);
    bd(0, n-1, 0);
    for (auto &[dkkf, r, l, k, kdk] : Q) {
        ans.clear();
        qry(0, n-1, l, r, 0);
        cout << ans[k-1] << '\n';
    }
}

