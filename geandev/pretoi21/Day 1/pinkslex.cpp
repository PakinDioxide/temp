#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;

ll fen[mxN], n;

void upd(int idx, ll x) { for (int i = idx; i < n+5; i += i & -i) fen[i] = max(fen[i], x); }
ll qr(int idx) { ll x = LLONG_MIN; for (int i = idx; i > 0; i -= i & -i) x = max(x, fen[i]); return x; }

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int k;
    cin >> n >> k;
    ll a[n+1], pl[n+1], pr[n+2];
    pl[0] = pr[n+1] = 0;
    vector <ll> cl, cr;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cl.emplace_back(0), cr.emplace_back(0);
    for (int i = 1; i <= n; i++) pl[i] = pl[i-1] + a[i], cl.emplace_back(pl[i]);
    for (int i = n; i >= 1; i--) pr[i] = pr[i+1] + a[i], cr.emplace_back(pr[i]);
    sort(cl.begin(), cl.end());
    sort(cr.begin(), cr.end());
    ll l = -1e15, r = 1e15, ans = 0;
    auto getl = [&] (ll x) { return upper_bound(cl.begin(), cl.end(), x) - cl.begin(); };
    auto getr = [&] (ll x) { return upper_bound(cr.begin(), cr.end(), x) - cr.begin(); };
    while (l <= r) {
        ll x = l + (r-l)/2;
        vector <ll> dpl(n+2), dpr(n+2);
        for (int i = 1; i < n+5; i++) fen[i] = LLONG_MIN;
        upd(getl(0), 0);
        // cout << "X " << x << '\n';
        for (int i = 1; i <= n; i++) {
            int it = getl(pl[i] - x);
            dpl[i] = qr(it) + 1;
            upd(getl(pl[i]), dpl[i]);
            // cout << i << ' ' << dpl[i] << '\n';
        }
        for (int i = 1; i < n+5; i++) fen[i] = LLONG_MIN;
        upd(getr(0), 0);
        for (int i = n; i >= 1; i--) {
            int it = getr(pr[i] - x);
            dpr[i] = qr(it) + 1;
            upd(getr(pr[i]), dpr[i]);
        }
        ll mx = 0;
        for (int i = 0; i <= n; i++) if (dpl[i] >= 0 && dpr[i+1] >= 0) mx = max(mx, dpl[i] + dpr[i+1]);
        if (mx >= k) l = x+1, ans = x;
        else r = x-1;
    }
    cout << ans << '\n';
    // for (auto &e : cl) cout << e << ' ';
    // cout << '\n';
    // ll x = 3;
    // vector <ll> dpl(n+2), dpr(n+2);
    // for (int i = 1; i < mxN; i++) fen[i] = LLONG_MIN;
    // upd(getl(0), 0);
    // cout << "X " << x << '\n';
    // for (int i = 1; i <= n; i++) {
    //     int it = getl(pl[i] - x);
    //     if (it == 0 || cl[it-1] != pl[i] - x) it--;
    //     dpl[i] = qr(it) + 1;
    //     upd(getl(pl[i]), dpl[i]);
    //     cout << i << ' ' << dpl[i] << ' ' << pl[i] - x << ' ' << pl[i] << '\n';
    //     cout << it << ' ' << getl(pl[i]) << '\n';
    //     cout << getl(pl[i] - x) << '\n';
    // }
}
/*
7 3
7 2 -6 4 3 4 -2
*/

/*
should do in nlogn, not nlog^2n
*/