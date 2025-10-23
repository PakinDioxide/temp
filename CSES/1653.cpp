/*
    author  : PakinDioxide
    created : 21/03/2025 11:18
    task    : 1653
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n, k;
    cin >> n >> k;
    ll a[n];
    for (auto &e : a) cin >> e;
    pair <ll, ll> dp[1 << n];
    dp[0] = {1, 0};
    for (ll i = 1; i < (1 << n); i++) {
        dp[i] = {LLONG_MAX, LLONG_MAX};
        for (ll j = 0; j < n; j++) {
            if (!(i & (1 << j))) continue;
            ll prev = i ^ (1 << j);
            auto [x, y] = dp[prev];
            ll nx = x + (y + a[j] > k), ny = (y + a[j] > k ? a[j] : y + a[j]);
            if (nx < dp[i].first) dp[i] = {nx, ny};
            else if (nx == dp[i].first) dp[i].second = min(dp[i].second, ny);
        }
    }
    cout << dp[(1 << n)-1].first << '\n';
}