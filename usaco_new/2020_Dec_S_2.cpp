/*
    author  : PakinDioxide
    created : 15/03/2025 13:18
    task    : 2020_Dec_S_2
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n, idx = 0, mxx = 0;
    cin >> n;
    pair <ll, ll> a[n];
    set <ll> ccx, ccy;
    vector <int> xx[n+1];
    for (auto &[x, y] : a) cin >> x >> y, ccx.insert(x), ccy.insert(y);
    map <ll, ll> mpx, mpy;
    for (auto e : ccx) mpx[e] = idx++; idx = 0;
    for (auto e : ccy) mpy[e] = idx++; idx = 0;
    for (auto &[x, y] : a) x = mpx[x], y = mpy[y], xx[x].push_back(y), mxx = max(mxx, x);
    sort(a, a+n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int mxh = -1, tmp = 0;
        multiset <ll> yy;
        if (i > 0 && a[i-1].first == a[i].first) mxh = a[i-1].second;
        for (int j = a[i].first; j <= mxx; j++) {
            for (auto e : xx[j]) yy.insert(e);
            int idx1 = distance(yy.begin(), yy.upper_bound(mxh));
            int idx2 = distance(yy.begin(), yy.lower_bound(a[i].second)) - 1;
            int idx3 = distance(yy.begin(), yy.upper_bound(a[i].second));
            int hv = 0;
            if (idx2 + 1 < idx3) hv = 1;
            cout << i << ' ' << j << ' ' << idx1 << ' ' << idx2 << ' ' << idx3 << ' ';
            ans += (idx2 - idx1 + 2) * (yy.size() - idx3 + 1) - 1 + hv;
            tmp += (idx2 - idx1 + 2) * (yy.size() - idx3 + 1) - 1 + hv;
            cout << (idx2 - idx1 + 2) * (yy.size() - idx3 + 1) - 1 + hv << '\n';
        }
        cout << i << ' ' << tmp << '\n';
    }
    cout << ans << '\n';
}