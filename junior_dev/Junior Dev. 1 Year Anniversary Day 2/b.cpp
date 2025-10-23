/*
    author  : PakinDioxide
    created : 23/09/2025 18:09
    task    : b
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q; cin >> n >> q;
    ll dp[1000005];
    for (auto &e : dp) e = LLONG_MAX;
    dp[0] = 0;
    ll a[101]; for (auto &e : a) e = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        ll x, y; cin >> x >> y;
        a[x] = min(a[x], y);
    }
    for (int d = 1; d <= 100; d++) if (a[d] < LLONG_MAX) for (int i = d; i <= 1000000; i++) if (dp[i-d] < LLONG_MAX) dp[i] = min(dp[i], dp[i-d] + a[d]);
    while (q--) {
        ll x; cin >> x; cout << (dp[x] == LLONG_MAX ? -1 : dp[x]) << '\n';
    }
    // while (q--) {
    //     ll x;
    //     if (x <= 100) {
    //         cout << (dp[x] == LLONG_MAX ? -1 : dp[x]) << '\n';
    //         continue;
    //     }
    //     ll mn = LLONG_MAX;
    //     for (int i = 1; i <= 100; i++) if (dp[i] != LLONG_MAX) {

    //     }
    // }
}