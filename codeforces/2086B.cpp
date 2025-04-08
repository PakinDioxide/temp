/*
    author  : PakinDioxide
    created : 03/04/2025 21:38
    task    : 2086B
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll n, k, x;
    cin >> n >> k >> x;
    ll a[n], sum = 0;
    for (auto &e : a) cin >> e, sum += e;
    ll ans = n*k;
    ans -= (x / sum) * n;
    x %= sum;
    ll idx = n-1;
    while (x > 0) x -= a[idx--], ans--;
    cout << min(n*k, max(0LL, ans+1)) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}