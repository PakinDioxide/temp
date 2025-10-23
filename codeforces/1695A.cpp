/*
    author  : 
    created : 14/06/2025 22:54
    task    : 1695A
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector <pair <ll, ll>> v, v2;
    ll a[n][m], mx = LLONG_MIN;
    for (auto &E : a) for (auto &e : E) cin >> e, mx = max(mx, e);
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (a[i][j] == mx) v.emplace_back(i, j);
    v2 = v;
    v.emplace_back(0, 0), v.emplace_back(0, m-1), v.emplace_back(n-1, 0), v.emplace_back(n-1, m-1);
    mx = 0;
    for (auto &x : v) for (auto &y : v2) mx = max(mx, (abs(x.first-y.first)+1)*(abs(x.second-y.second)+1));
    cout << mx << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}