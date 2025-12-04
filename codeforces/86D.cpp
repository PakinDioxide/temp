#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q; cin >> n >> q;
    ll a[n], ans[q]; for (auto &e : a) cin >> e;
    vector <tuple <int, int, int, int>> v;
    int sqT = ceil(sqrt(n));
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r; v.emplace_back(l/sqT, --r, --l, i);
    }
    sort(v.begin(), v.end());
    int L = 0, R = -1;
    vector <int> cnt(1e6+5);
    ll s = 0;
    auto exp = [&] (ll x) {
        ll k = cnt[x];
        s -= x * k * k; cnt[x] = ++k;
        s += x * k * k;
    };
    auto rmv = [&] (ll x) {
        ll k = cnt[x];
        s -= x * k * k; cnt[x] = --k;
        s += x * k * k;
    };
    for (auto &[ii, r, l, idx] : v) {
        while (L > l) exp(a[--L]);
        while (R < r) exp(a[++R]);
        while (L < l) rmv(a[L++]);
        while (R > r) rmv(a[R--]);
        ans[idx] = s;
    }
    for (auto &e : ans) cout << e << '\n';
}