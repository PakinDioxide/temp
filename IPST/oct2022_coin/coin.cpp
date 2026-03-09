#include "coin.h"
#include <bits/stdc++.h>

using namespace std;

const int mxN = 2e5+5;

int N, L;

struct SEG {
    int TYPE, seg[4*mxN], lz[4*mxN];

    void build() { memset(seg, 0, sizeof(seg)), memset(lz, 0, sizeof(lz)); }

    void push(int u) {
        if (TYPE == 0 || lz[u] == 0) return;
        seg[u<<1] += lz[u];
        seg[u<<1|1] += lz[u];
        lz[u<<1] += lz[u];
        lz[u<<1|1] += lz[u];
        lz[u] = 0;
    }

    void upd(int l, int r, int idx, int x, int u) {
        if (l == r) seg[u] = x;
        else {
            push(u);
            int m = l + (r-l)/2;
            if (m >= idx) upd(l, m, idx, x, u<<1);
            else upd(m+1, r, idx, x, u<<1|1);
            if (TYPE) seg[u] = max(seg[u<<1], seg[u<<1|1]);
            else seg[u] = seg[u<<1] + seg[u<<1|1];
        }
    }

    void UPD(int l, int r, int x, int y, int u) {
        if (y < x) return;
        if (x <= l && r <= y) seg[u]++, lz[u]++;
        else {
            push(u);
            int m = l + (r-l)/2;
            if (m >= x) UPD(l, m, x, y, u<<1);
            if (m+1 <= y) UPD(m+1, r, x, y, u<<1|1);
            seg[u] = max(seg[u<<1], seg[u<<1|1]);
        }
    }

    int qr(int l, int r, int x, int y, int u) {
        if (y < x) return 0;
        if (x <= l && r <= y) return seg[u];
        else {
            push(u);
            int m = l + (r-l)/2, k = 0;
            if (TYPE) {
                if (m >= x) k = max(k, qr(l, m, x, y, u<<1));
                if (m+1 <= y) k = max(k, qr(m+1, r, x, y, u<<1|1));
            } else {
                if (m >= x) k += qr(l, m, x, y, u<<1);
                if (m+1 <= y) k += qr(m+1, r, x, y, u<<1|1);
            }
            return k;
        }
    }

    int QR(int l, int r, int x, int u) {
        if (seg[u] < x) return N;
        if (l == r) return l;
        else {
            push(u);
            int m = l + (r-l)/2;
            if (seg[u<<1] >= x) return QR(l, m, x, u<<1);
            else return QR(m+1, r, x-seg[u<<1], u<<1|1);
        }
    }
};

SEG cnt, mx;

vector <pair <int, int>> V;

void initialize(int n, vector <int> A, int l) {
    N = n, L = l;
    cnt.TYPE = 0, mx.TYPE = 1;
    cnt.build(); mx.build();
    for (int i = 0; i < N; i++) V.emplace_back(A[i], i);
    sort(V.begin(), V.end());
}



int solve(int A, int B, int C) {
    // cout << "A " << A << ' ' << B << ' ' << C << '\n';
    while (V.size() && V.back().first > C) {
        cnt.upd(0, N-1, V.back().second, 1, 1);
        mx.UPD(0, N-1, max(0, V.back().second-L+1), V.back().second, 1);
        V.pop_back();
        // for (int i = 0; i < N; i++) cout << mx.qr(0, N-1, i, i, 1) << ' '; cout << '\n';
    }

    B++;
    B += (A == 0 ? 0 : cnt.qr(0, N-1, 0, A-1, 1));
    // cout << "B " << B << '\n';
    int IDX = cnt.QR(0, N-1, B, 1);
    // cout << "IDX " << IDX << '\n';
    if (IDX == N) return N;
    B += mx.qr(0, N-1, A, IDX, 1);
    // cout << "B2 " << B << '\n';
    return cnt.QR(0, N-1, B, 1);
}

vector <int> max_dist(vector <vector <int>> c) {
    int Q = c.size();
    vector <int> ans(Q);
    vector <vector <int>> C;
    for (int i = 0; i < Q; i++) C.emplace_back(vector <int> {c[i][2], c[i][0], c[i][1], i});
    sort(C.begin(), C.end());
    reverse(C.begin(), C.end());
    for (auto &e : C) {
        ans[e[3]] = solve(e[1], e[2], e[0]);
    }
    return ans;
}

/*
7 2 0
1 2 3 4 3 2 1
0 3 2
2 1 2

7 3 2
1 2 1 3 1 3 3
1 1 2
1 0 1
1 1 1

*/
