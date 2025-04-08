/*
    author  : PakinDioxide
    created : 29/03/2025 01:59
    task    : JOI19_ho_t2
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n, m;
    cin >> n >> m;
    pair <ll, ll> a[n];
    ll c[m];
    for (auto &[y, x] : a) cin >> x >> y;
    for (auto &e : c) cin >> e;
    sort(a, a+n);
    sort(c, c+m);
    ll pos[n];
    for (int i = 0; i < n; i++) pos[i] = lower_bound(c, c+m, a[i].second) - c;
    vector <ll> d;
    for (auto &e : pos) {
        if (e == m) continue;
        int psh = 0;
        if (!d.empty() && d.back() < m-1 && d.back() + 1 > e) d.emplace_back(d.back() + 1), psh = 1;
        int idx = lower_bound(d.begin(), d.end(), e) - d.begin();
        if (idx != d.size()) {
            while (d[idx] == e && idx+1 < d.size() && e+1 < m) e++, idx++;
            d[idx] = e;
        } else if (!psh) d.emplace_back(e);
    }
    cout << d.size() << '\n';
}