/*
    author  : PakinDioxide
    created : 05/04/2025 15:10
    task    : D
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n, q;
    cin >> n >> q;
    map <ll, ll> mp;
    set <ll> cmp;
    for (int i = 0; i < n; i++) {
        ll l, r, k;
        cin >> l >> r >> k;
        r--;
        mp[l-1] += k;
        mp[r] -= k;
        cmp.emplace(l-1), cmp.emplace(r);
    }
    pair <ll, ll> Q[q];
    for (auto &[x, y] : Q) cin >> x >> y, x--, y--, cmp.emplace(x), cmp.emplace(y);
    n = cmp.size();
    ll p[n], idx = 0, r, v = 0;
    p[0] = 0;
    map <ll, ll> ccmp;
    for (auto &e : cmp) {
        ccmp[e] = idx;
        if (idx == 0) {v += mp[e]; r = e; idx++; continue;}
        p[idx] = p[idx-1] + v * (e - r);
        v += mp[e];
        r = e;
        idx++;
    }
    for (auto &[x, y] : Q) cout << p[ccmp[y]] - p[ccmp[x]] << '\n';
}