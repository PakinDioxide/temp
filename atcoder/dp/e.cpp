/*
    author  : PakinDioxide
    created : 24/03/2025 20:36
    task    : e
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n, k;
    cin >> n >> k;
    ll dp[100005];
    for (int i = 0; i <= 100000; i++) dp[i] = LLONG_MAX;
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        ll w, v;
        cin >> w >> v;
        for (int j = 100000; j >= v; j--) if (dp[j-v] < LLONG_MAX) dp[j] = min(dp[j], dp[j-v]+w);
    }
    ll ans = 0;
    for (int i = 0; i <= 100000; i++) if (dp[i] <= k) ans = i;
    cout << ans << '\n';
}