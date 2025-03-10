#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector <pair <ll, ll>> v;
    pair <ll, ll> a[n];
    for (auto &e : a) cin >> e.first;
    for (auto &e : a) cin >> e.second;
    for (auto [x, y] : a) {
        v.emplace_back(x, 1);
        v.emplace_back(x+1, -1);
        v.emplace_back(y, 1);
        v.emplace_back(y+1, 0);
    }
    ll cnt = n, neg = 0, mx = 0;
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        auto [x, y] = v[i];
        if (y == -1) neg++;
        else if (y == 0) cnt--, neg--;
        // cout << x << ' ' << y << ' ' << cnt << ' ' << neg << '\n';
        if (i < v.size()-1 && v[i+1].first == x) continue;
        if (neg <= k) mx = max(mx, cnt*x);
    }
    cout << mx << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}