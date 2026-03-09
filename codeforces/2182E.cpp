#include <bits/stdc++.h>
#define ll long long
#define int ll

using namespace std;

const int mxN = 2e5+5;

pair <ll, ll> seg[4*mxN];
pair <ll, ll> b[mxN];

void build(int l, int r, int u) {
    if (l == r) seg[u] = make_pair(b[l].second, l);
    else {
        int m = l + (r-l)/2;
        build(l, m, u<<1);
        build(m+1, r, u<<1|1);
        seg[u] = max(seg[u<<1], seg[u<<1|1]);
    }
}

void upd(int l, int r, int x, int u) {
    if (l == r) seg[u] = make_pair(LLONG_MIN, l);
    else {
        int m = l + (r-l)/2;
        if (m >= x) upd(l, m, x, u<<1);
        else upd(m+1, r, x, u<<1|1);
        seg[u] = max(seg[u<<1], seg[u<<1|1]);
    }
}

pair <ll, ll> qr(int l, int r, int x, int y, int u) {
    if (x <= l && r <= y) return seg[u];
    else if (r < x || y < l) return {LLONG_MIN, -1};
    else {
        int m = l + (r-l)/2;
        return max(qr(l, m, x, y, u<<1), qr(m+1, r, x, y, u<<1|1));
    }
}

void solve() {
    int n, m, k; cin >> n >> m >> k;
    ll a[m]; for (auto &e : a) cin >> e;
    sort(a, a+m);
    for (int i = 0; i < n; i++) {
        ll x, y, z; cin >> x >> y >> z;
        k -= y;
        z -= y;
        b[i] = make_pair(x, z);
    }
    sort(b, b+n);
    build(0, n-1, 1);
    ll cnt = 0, vis[n+1]; memset(vis, 0, sizeof(vis));
    int it = -1;
    for (auto &e : a) {
        while (it+1 < n && b[it+1].first <= e) it++;
        if (it < 0) continue;
        pair <ll, ll> K = qr(0, n-1, 0, it, 1);
        if (K.first > LLONG_MIN) {
            vis[K.second] = 1;
            cnt++;
            upd(0, n-1, K.second, 1);
        }
    }
    vector <ll> v;
    for (int i= 0; i < n; i++) if (!vis[i]) v.emplace_back(b[i].second);
    sort(v.begin(), v.end());
    for (auto &e : v) {
        if (e <= k) k -= e, cnt++;
        else break;
    }
    cout << cnt << '\n';
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

