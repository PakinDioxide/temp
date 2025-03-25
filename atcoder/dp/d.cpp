/*
    author  : PakinDioxide
    created : 24/03/2025 20:32
    task    : d
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n, k;
    cin >> n >> k;
    ll dp[k+1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
        ll w, v;
        cin >> w >> v;
        for (int j = k; j >= w; j--) dp[j] = max(dp[j], dp[j-w] + v);
    }
    cout << dp[k] << '\n';
}