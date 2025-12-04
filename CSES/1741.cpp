#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e6+10;

pair <int, int> seg[4*mxN];
int lz[4*mxN];

pair <int, int> mg(const pair <int, int> &l, const pair <int, int> &r) {
    if (l.first < r.first) return l;
    else if (r.first < l.first) return r;
    else return make_pair(l.first, l.second + r.second);
}

void push(int u) {
    if (lz[u] == 0) return;
    seg[u<<1].first += lz[u];
    seg[u<<1|1].first += lz[u];
    lz[u<<1] += lz[u];
    lz[u<<1|1] += lz[u];
    lz[u] = 0;
}

void build(int l, int r, int u) {
    if (l == r) seg[u] = make_pair(0, 1);
    else {
        int m = l + (r-l)/2;
        build(l, m, u<<1);
        build(m+1, r, u<<1|1);
        seg[u] = mg(seg[u<<1], seg[u<<1|1]);
    }
}

void upd(int l, int r, int x, int y, int k, int u) {
    if (x <= l && r <= y) seg[u].first += k, lz[u] += k;//, push(u);
    else {
        push(u);
        int m = l + (r-l)/2;
        if (m >= x) upd(l, m, x, y, k, u<<1);
        if (m+1 <= y) upd(m+1, r, x, y, k, u<<1|1);
        seg[u] = mg(seg[u<<1], seg[u<<1|1]);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    vector <tuple <ll, ll, ll, int>> v;
    for (int i = 0; i < n; i++) {
        ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        y1 += 1e6+1, y2 += 1e6+1;
        v.emplace_back(x1, y1, y2-1, 1);
        v.emplace_back(x2, y1, y2-1, 0);
    }
    sort(v.begin(), v.end());
    int sz = 2e6+5;
    build(1, sz, 1);
    ll ans = 0;
    for (int i = 0; i < v.size(); i++) {
        auto [x, l, r, t] = v[i];
        if (t == 1) upd(1, sz, l, r, 1, 1);
        else upd(1, sz, l, r, -1, 1);
        if (i < v.size()-1 && get<0>(v[i+1]) == x) continue;
        if (i == v.size()-1) continue;
        ans += (ll) (sz - (seg[1].first == 0 ? seg[1].second : 0)) * (get<0>(v[i+1]) - x);
    }
    cout << ans << '\n';
}