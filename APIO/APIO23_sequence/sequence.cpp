#include "sequence.h"
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 5e5+5;

int N;

struct PST {
    int seg[mxN], it = 0;
    struct {
        int val, L, R, l, r; // L is expand to left
    } pool[mxN << 5];

    int nw(int x) {
        pool[++it] = {x, max(x, 0), max(x, 0), 0, 0};
        return it;
    }

    int nw(int l, int r) {
        pool[++it] = {pool[l].val + pool[r].val, 
            max({0, pool[l].L + pool[r].val, pool[r].L}),
            max({0, pool[r].R + pool[l].val, pool[l].R}),
            l, r};
        return it;
    }

    int build(int l, int r, int x) {
        if (l == r) return nw(x);
        else {
            int m = l + (r-l)/2;
            return nw(build(l, m, x), build(m+1, r, x));
        }
    }

    int upd(int l, int r, int idx, int x, int u) {
        if (l == r) return nw(x);
        else {
            int m = l + (r-l)/2;
            if (m >= idx) return nw(upd(l, m, idx, x, pool[u].l), pool[u].r);
            else return nw(pool[u].l, upd(m+1, r, idx, x, pool[u].r));
        }
    }

    int QR(int l, int r, int x, int y, int u) {
        if (x <= l && r <= y) return pool[u].val;
        else {
            int m = l + (r-l)/2, k = 0;
            if (m >= x) k += QR(l, m, x, y, pool[u].l);
            if (m+1 <= y) k += QR(m+1, r, x, y, pool[u].r);
            return k;
        }
    }

    pair <int, int> QR_l(int l, int r, int idx, int u) {
        if (idx < 0 || idx >= N) return make_pair(0, 0);
        if (r <= idx) return make_pair(pool[u].L, pool[u].val);
        else {
            int m = l + (r-l)/2;
            if (idx <= m) return QR_l(l, m, idx, pool[u].l);
            pair <int, int> B = QR_l(m+1, r, idx, pool[u].r);
            return make_pair(max({0, pool[pool[u].l].L + B.second, B.first}), pool[pool[u].l].val + B.second);
        }
    }

    pair <int, int> QR_r(int l, int r, int idx, int u) {
        if (idx < 0 || idx >= N) return make_pair(0, 0);
        if (l >= idx) return make_pair(pool[u].R, pool[u].val);
        else {
            int m = l + (r-l)/2;
            if (idx > m) return QR_r(m+1, r, idx, pool[u].r);
            pair <int, int> B = QR_r(l, m, idx, pool[u].l);
            return make_pair(max({0, pool[pool[u].r].R + B.second, B.first}), pool[pool[u].r].val + B.second);
        }
    }
} T, T2;

int sequence(int n, vector <int> A) {
    N = n;
    T.seg[0] = T.build(0, N-1, -1);
    T2.seg[0] = T2.build(0, N-1, 1);
    vector <pair <int, int>> V;
    for (int i = 0; i < N; i++) V.emplace_back(A[i], i);
    V.emplace_back(0, 0);
    sort(V.begin(), V.end());
    int prev[N+1]; memset(prev, 0, sizeof(prev));
    for (int i = 1; i <= N; i++) {
        if (i == 1 || V[i].first != V[i-1].first) prev[V[i].first] = V[i-1].first;
        T.seg[V[i].first] = T.upd(0, N-1, V[i].second, 1, T.seg[V[i-1].first]);
        T2.seg[V[i].first] = T2.upd(0, N-1, V[i].second, -1, T2.seg[V[i-1].first]);
    }
    vector <int> a[N+1];
    for (int i = 0; i < N; i++) a[A[i]].emplace_back(i);
    int ans = 0;
    for (int i = 1; i <= N; i++) if (a[i].size()) {
        int q = -1;
        for (int p = 0; p < (int) a[i].size(); p++) {
            int ok = 0;
            do {
                q = min(q+1, (int) a[i].size() - 1);
                int u = a[i][p], v = a[i][q];
                int fx = T.QR(0, N-1, u, v, T.seg[prev[i]]) + T.QR(0, N-1, u, v, T.seg[i]);
                assert(fx % 2 == 0);
                fx /= 2;
                int MX = T.QR_l(0, N-1, u-1, T.seg[i]).first + T.QR_r(0, N-1, v+1, T.seg[i]).first;
                // cout << T.QR_l(0, N-1, i-1, T.seg[i]).first << ' ';
                // cout << T.QR_r(0, N-1, idx+1, T.seg[i]).first << '\n';
                // cout << MX << '\n';
                int MN = -(T2.QR_l(0, N-1, u-1, T.seg[prev[i]]).first + T2.QR_r(0, N-1, v+1, T.seg[prev[i]]).first);
                // cout << i << ' ' << p << ' ' << q << ' ' << MX << ' ' << MN << ' ' << fx << '\n';
                MX += fx;
                MN += fx;
                // cout << x << ' ' << i << ' ' << idx << '\n';
                if (!(MX < -(q-p+1) || MN > (q-p+1))) ok = 1, ans = max(ans, q-p+1);
                else ok = 0;
            } while (ok && q+1 < (int) a[i].size());
        }
    }
    return ans;
}
