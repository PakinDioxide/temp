#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    ll a[n]; for (auto &e : a) cin >> e;
    vector <tuple <int, int, ll>> Q(m);
    vector <pair <int, int>> V;
    for (auto &[l, r, x] : Q) {
        cin >> l >> r >> x;
        V.emplace_back(
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

