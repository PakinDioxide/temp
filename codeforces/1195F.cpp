#include <bits/stdc++.h>
#define ll long long

using namespace std;

pair <int, int> dv(int x, int y) {
    int g = __gcd(x, y);
    return make_pair(x/g, y/g);
}

const int mxN = 1e5+5;
const int mxK = 3e5+5;

int fen[mxN], n, rc[mxK], ans[mxN];

void upd(int idx, int x) { for (int i = idx; i <= n; i += i & -i) fen[i] += x; }
int qr(int idx) { int x = 0; for (int i = idx; i > 0; i -= i & -i) x += fen[i]; return x; }

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    vector <pair <int, int>> cc;
    vector <vector <pair <int, int>>> A(n);
    vector <vector <int>> a(n);
    for (int ii = 0; ii < n; ii++) {
        int k; cin >> k;
        vector <pair <int, int>> v(k);
        for (auto &[x, y] : v) cin >> x >> y;
        // cout << ii << '\n';
        for (int i = 0; i < k; i++) {
            int j = (i + 1) % k;
            pair <int, int> x = dv(v[j].second - v[i].second, v[j].first - v[i].first);
            if (v[i].first > v[j].first || (v[i].first == v[j].first && v[i].second < v[j].second)) x.first *= -1, x.second *= -1;
            // cout << x.first << ' ' << x.second << '\n';
            cc.emplace_back(x);
            A[ii].emplace_back(x);
        }
    }
    sort(cc.begin(), cc.end());
    cc.resize(unique(cc.begin(), cc.end()) - cc.begin());
    for (int i = 0; i < n; i++) for (auto &e : A[i]) a[i].emplace_back(lower_bound(cc.begin(), cc.end(), e) - cc.begin() + 1);
    fill(rc, rc+mxK, -1);
    int q; cin >> q;
    vector <vector <pair <int, int>>> Q(n);
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r; --l, --r;
        Q[r].emplace_back(l, i);
    }
    for (int i = 0; i < n; i++) {
        for (auto &e : a[i]) {
            if (rc[e] != -1) upd(rc[e], -1);
            rc[e] = i+1;
            upd(rc[e], 1);
        }
        for (auto &[l, idx] : Q[i]) {
            ans[idx] = qr(i+1) - qr(l);
        }
    }
    for (int i = 0; i < q; i++) cout << ans[i] << '\n';
}

