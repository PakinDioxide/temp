/*
    author  : PakinDioxide
    created : 19/04/2025 21:39
    task    : 2096B
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    ll l[n], r[n];
    ll ans = 0;
    for (auto &e : l) cin >> e;
    for (auto &e : r) cin >> e;
    for (int i = 0; i < n; i++) if (l[i] < r[i]) swap(l[i], r[i]);
    sort(l, l+n), sort(r, r+n), reverse(l, l+n), reverse(r, r+n);
    for (auto &e : l) ans += e;
    for (int i = 0; i < k-1; i++) ans += r[i];
    ans++;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}