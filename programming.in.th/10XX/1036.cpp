/*
    author  : PakinDioxide
    created : 16/04/2025 22:55
    task    : 1036
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n >> k;
    pair <ll, ll> a[n];
    for (auto &[x, y] : a) {
        cin >> x;
        y = 0;
        for (int i = 0; i < k; i++) {
            int z;
            cin >> z;
            y = (y << 1) + z;
        }
    }
    ll dp[1 << k];
    for (int i = 0; i < (1 << k); i++) dp[i] = LLONG_MAX;
    dp[0] = 0;
    for (int i = 0; i < (1 << k); i++) if (dp[i] < LLONG_MAX) for (auto &[x, y] : a) dp[i|y] = min(dp[i|y], dp[i] + x);
    cout << dp[(1 << k)-1] << '\n';
}