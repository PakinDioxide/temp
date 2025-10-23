/*
    author  : PakinDioxide
    created : 22/05/2025 01:59
    task    : 2020_Jan_G_3_2
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;

struct T {
    ll x, y, idx;
    bool operator<(const T &o) const {
        return (y < o.y ? 1 : y == o.y ? x < o.x : 0);
    }
};

ll n, k;
vector <ll> cx;
vector <T> v;
ll fen[2*mxN], P[mxN];

void upd(int idx, ll x) { for (int i = idx; i <= 2*n+2; i += i & -i) fen[i] = min(fen[i], x); }
ll qr(int idx) { ll x = LLONG_MAX; for (int i = idx; i > 0; i -= i & -i) x = min(x, fen[i]); return x; }

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("boards.in", "r", stdin);
    freopen("boards.out", "w", stdout);
    cin >> k >> n;
    for (int i = 1; i <= n; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        v.emplace_back(T{x1, y1, i});
        v.emplace_back(T{x2, y2, i});
        cx.emplace_back(x1);
        cx.emplace_back(x2);
        P[i] = LLONG_MAX;
    }
    v.emplace_back(T{k, k, n+1}); P[n+1] = LLONG_MAX;
    cx.emplace_back(k), cx.emplace_back(0);
    for (int i = 1; i <= 2*n+2; i++) fen[i] = LLONG_MAX;
    sort(cx.begin(), cx.end());
    sort(v.begin(), v.end());
    upd(upper_bound(cx.begin(), cx.end(), 0) - cx.begin(), 2*k);
    for (auto &e : v) {
        P[e.idx] = min(P[e.idx], qr(upper_bound(cx.begin(), cx.end(), e.x) - cx.begin()) - (k-e.x) - (k-e.y));
        upd(upper_bound(cx.begin(), cx.end(), e.x) - cx.begin(), P[e.idx] + (k-e.x) + (k-e.y));
    }
    cout << P[n+1] << '\n';
}