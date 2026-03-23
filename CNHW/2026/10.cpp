#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 5e5+5;

int n, q, a[mxN], deg[mxN], ans[mxN];
vector <tuple <int, int, int>> Q;
vector <int> adj[mxN];
vector <pair <int, int>> A;
multiset <pair <int, int>> ms, L, R;

struct SEG {
    int seg[4*mxN], lz[4*mxN];

    void push(int u) {
        seg[u<<1] += lz[u];
        seg[u<<1|1] += lz[u];
        lz[u<<1] += lz[u];
        lz[u<<1|1] += lz[u];
        lz[u] = 0;
    }

    void build(int l, int r, int u) {
        if (l == r) seg[u] = INT_MIN, lz[u] = 0;
        else {
            int m = l + (r-l)/2;
            build(l, m, u<<1);
            build(m+1, r, u<<1|1);
            seg[u] = max(seg[u<<1], seg[u<<1|1]);
            lz[u] = 0;
        }
    }

    void upd(int l, int r, int x, int y, int k, int u) {
        if (y > x) return;
        if (x <= l && r <= y) seg[u] += k, lz[u] += k;
        else {
            push(u);
            int m = l + (r-l)/2;
            if (m >= x) upd(l, m, x, y, k, u<<1);
            if (m+1 <= y) upd(m+1, r, x, y, k, u<<1|1);
            seg[u] = max(seg[u<<1], seg[u<<1|1]);
        }
    }

    void st(int l, int r, int x, int k, int u) {
        if (l == r) seg[u] = k, lz[u] = 0;
        else {
            push(u);
            int m = l + (r-l)/2;
            if (m >= x) st(l, m, x, k, u<<1);
            else st(m+1, r, x, k, u<<1|1);
            seg[u] = max(seg[u<<1], seg[u<<1|1]);
        }
    }

    int qr(int l, int r, int k, int u) {
        if (seg[u] < k) return -1;
        if (l == r) return l;
        else {
            push(u);
            int m = l + (r-l)/2;
            if (seg[u<<1] >= k) return qr(l, m, k, u<<1);
            else return qr(m+1, r, k, u<<1|1);
            seg[u] = max(seg[u<<1], seg[u<<1|1]);
        }
    }
} T;

struct FEN {
    int fen[mxN];
    void build() { memset(fen, 0, sizeof(fen)); }
    void upd(int idx, int x) { for (int i = idx; i <= n; i += i & -i) fen[i] += x; }
    int qr(int idx) { int x = 0; for (int i = idx; i > 0; i -= i & -i) x += fen[i]; return x; }
} fw;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0, l, r; i < q; i++) cin >> l >> r, Q.emplace_back(r, -l, i);
    sort(Q.begin(), Q.end());
    for (int i = 0; i < q; i++) {
        auto &[r, l, id] = Q[i]; 
        l = -l;
        while (ms.size() && (*prev(ms.end())).first >= l) {
            deg[(*prev(ms.end())).second]++;
            adj[i].emplace_back((*prev(ms.end())).second);
            ms.erase(prev(ms.end()));
        }
        ms.emplace(l, i);
    }
    fw.build();
    T.build(0, q-1, 1);
    for (int i = 1; i <= n; i++) A.emplace_back(a[i], i);
    sort(A.begin(), A.end());
    for (int i = 1; i <= n; i++) fw.upd(i, 1);
    for (int i = 0; i < q; i++) if (deg[i] == 0) {
        L.emplace(get<1>(Q[i]), i);
        R.emplace(get<0>(Q[i]), i);
        T.st(0, q-1, i, fw.qr(get<0>(Q[i])) - fw.qr(get<1>(Q[i]) - 1), 1);
    }
    for (int x = n; x >= 0; x--) {
        while (A.size() && A.back().first >= x) {
            int idx = A.back().second;
            A.pop_back();
            fw.upd(idx, -1);
            auto itl = R.lower_bound(make_pair(idx, INT_MIN));
            auto itr = L.upper_bound(make_pair(idx, INT_MAX));
            if (itl == R.end() || itr == L.begin()) continue;
            itr = prev(itr);
            int id_l = (*itl).second, id_r = (*itr).second;
            if (id_l > id_r) continue;
            T.upd(0, q-1, id_l, id_r, -1, 1);
        }
        int idx = T.qr(0, q-1, x, 1);
        while (idx > -1) {
            ans[get<2>(Q[idx])] = x;
            L.erase(L.find(make_pair(get<1>(Q[idx]), idx)));
            R.erase(R.find(make_pair(get<0>(Q[idx]), idx)));
            T.st(0, q-1, idx, INT_MIN, 1);
            for (auto &e : adj[idx]) {
                L.emplace(get<1>(Q[e]), e);
                R.emplace(get<0>(Q[e]), e);
                T.st(0, q-1, e, fw.qr(get<0>(Q[e])) - fw.qr(get<1>(Q[e]) - 1), 1);
            }
            idx = T.qr(0, q-1, x, 1);
        }
    }
    for (int i = 0; i < q; i++) cout << ans[i] << '\n';
}

