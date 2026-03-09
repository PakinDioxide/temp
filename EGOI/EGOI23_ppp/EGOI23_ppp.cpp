#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;

struct Node {
    int val, l, r;
};

Node pool[mxN<<5];
int seg[mxN], it = 0;

int nw(int x) {
    pool[++it] = {x, 0, 0};
    return it;
}

int nw(int l, int r) {
    pool[++it] = {max(pool[l].val, pool[r].val), l, r};
    return it;
}

int build(int l, int r) {
    if (l == r) return nw(0);
    else {
        int m = l + (r-l)/2;
        return nw(build(l, m), build(m+1, r));
    }
}

int upd(int l, int r, int x, int k, int u) {
    if (l == r) return nw(pool[u].val + k);
    else {
        int m = l + (r-l)/2;
        if (m >= x) return nw(upd(l, m, x, k, pool[u].l), pool[u].r);
        else return nw(pool[u].l, upd(m+1, r, x, k, pool[u].r));
    }
}

int qr(int l, int r, int u) {
    if (l == r) return l;
    else {
        int m = l + (r-l)/2;
        if (pool[pool[u].l].val >= pool[pool[u].r].val) return qr(l, m, pool[u].l);
        else return qr(m+1, r, pool[u].r);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m; cin >> n >> m;
    vector <pair <int, int>> Q(m);
    for (auto &[x, y] : Q) cin >> x >> y;
    int lst[n], ans[n]; for (auto &e : lst) e = m; memset(ans, 0, sizeof(ans));
    seg[m] = build(0, n-1);
    for (int i = m-1; i >= 0; i--) {
        auto &[x, y] = Q[i];
        lst[y] = i;
        seg[i] = upd(0, n-1, x, lst[x] - i, seg[lst[x]]);
        ans[qr(0, n-1, seg[i])]++;
    }
    for (int i = 0; i < n; i++) cout << ans[i] << ' '; cout << '\n';
}
