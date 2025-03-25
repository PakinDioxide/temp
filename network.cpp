/*
    author  : PakinDioxide
    created : 25/03/2025 15:29
    task    : network
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n, m;
    cin >> n >> m;
    vector <pair <ll, ll>> v;
    for (int i = 0; i < n; i++) {
        ll s, e, w;
        cin >> s >> e >> w;
        v.emplace_back(s, w);
        v.emplace_back(e+1, -w);
    }
    sort(v.begin(), v.end());
    vector <pair <ll, ll>> ans;
    ll st = 1;
    ll k = 0;
    for (int i = 0; i < v.size(); i++) {
        auto [x, e] = v[i];
        k += e;
        if (i < v.size()-1 && v[i].first == v[i+1].first) continue;
        if (k < m) {
            if (st == 0) ans.back().second = x-1, st = 1;
        } else {
            if (st == 1) ans.emplace_back(x, x), st = 0;
        }
    }
    for (auto &[x, y] : ans) cout << x << ' ' << y << '\n';
}