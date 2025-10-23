/*
    author  : PakinDioxide
    created : 23/05/2025 22:06
    task    : toi21_crystal
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5, mxU = 1e3+5;

struct T {
    ll t, p, w;
    bool operator<(const T &o) {
        return t < o.t;
    }
};

ll U, K, N, fen[mxU][mxN], ans = 0;
vector <ll> cmp;
T a[mxN];

void upd(int idx, ll x, int k) { for (int i = idx; i <= N; i += i & -i) fen[k][i] = max(fen[k][i], x); }
ll qr(int idx, int k) { ll x = 0; for (int i = idx; i > 0; i -= i & -i) x = max(x, fen[k][i]); return x; }

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> U >> K >> N;
    for (int i = 1; i <= N; i++) cin >> a[i].p >> a[i].w >> a[i].t, cmp.emplace_back(a[i].p);
    sort(a+1, a+N+1);
    sort(cmp.begin(), cmp.end());
    for (int i = 1; i <= N; i++) {
        ll mx = 0, idx = upper_bound(cmp.begin(), cmp.end(), a[i].p) - cmp.begin();
        mx = max(mx, qr(idx-1, a[i].w)+1);
        mx = max(mx, qr(idx-1, U+1)+1-K);
        ans = max(ans, mx);
        upd(idx, mx, a[i].w), upd(idx, mx, U+1);
    }
    cout << ans << '\n';
}