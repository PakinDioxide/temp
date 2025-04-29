/*
    author  : PakinDioxide
    created : 24/04/2025 21:54
    task    : 2106D
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    ll a[n], b[m];
    for (auto &e : a) cin >> e;
    for (auto &e : b) cin >> e;
    pair <ll, ll> l[n], r[n];
    for (int i = 0; i < n; i++) {
        l[i] = (i > 0 ? l[i-1] : make_pair(0LL, 0LL));
        l[i].second = max(l[i].second, a[i]);
        if (l[i].first < m && l[i].second >= b[l[i].first]) l[i].first++, l[i].second = 0;
    }
    for (int i = n-1; i >= 0; i--) {
        r[i] = (i < n-1 ? r[i+1] : make_pair((ll) m-1, 0LL));
        r[i].second = max(r[i].second, a[i]);
        if (r[i].first >= 0 && r[i].second >= b[r[i].first]) r[i].first--, r[i].second = 0;
    }
    ll ans = LLONG_MAX;
    if (r[0].first < 0) ans = 0;
    else if (r[0].first == 0) ans = min(ans, b[0]);
    if (l[n-1].first >= m) ans = 0;
    else if (l[n-1].first == m-1) ans = min(ans, b[m-1]);
    for (int i = 0; i < n-1; i++) {
        // cout << i << ' ' << l[i].first << ' ' << r[i+1].first << '\n';
        if (l[i].first + (m-1-r[i+1].first) >= m) {ans = 0; break;}
        else if (l[i].first + (m-1-r[i+1].first) == m-1) ans = min(ans, b[l[i].first]);
    }
    cout << (ans == LLONG_MAX ? -1 : ans) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}