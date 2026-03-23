#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5 + 5;

struct {
    int l, r, vv, ans;
} pool[mxN<<7];

int it = 0;

int nw() {
    pool[++it] = {0, 0, 0, 0};
    return it;
}

int rt, N, K;

void upd(ll x, int k, int TP, int u) {
    if (k == K) {
        if (pool[u].vv == 0) pool[u].ans = 0;
        else pool[u].ans = INT_MIN;
    } else {
        int id = ((x >> k) & 1LL);
        if (id == 0) {
            if (pool[u].l == 0) pool[u].l = nw();
            pool[pool[u].l].vv += TP;
            upd(x, k+1, TP, pool[u].l);
        } else {
            if (pool[u].r == 0) pool[u].r = nw();
            pool[pool[u].r].vv += TP;
            upd(x, k+1, TP, pool[u].r);
        }
        int P = pool[pool[u].l].vv * k + pool[pool[u].r].ans;
        int Q = pool[pool[u].r].vv * k + pool[pool[u].l].ans;
        pool[u].ans = max(P, Q);
    }
}

void solve() {
    int q; cin >> N >> q >> K;
    ll a[N+1]; for (int i = 1; i <= N; i++) cin >> a[i];
    it = 0;
    rt = nw();
    for (int i = 1; i <= N; i++) upd(a[i], 0, 1, rt);
    cout << pool[rt].ans << '\n';
    while (q--) {
        int idx; ll x;
        cin >> idx >> x;
        upd(a[idx], 0, -1, rt);
        a[idx] = x;
        upd(a[idx], 0, 1, rt);
        cout << pool[rt].ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

