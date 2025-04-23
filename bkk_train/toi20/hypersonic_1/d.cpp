/*
    author  : PakinDioxide
    created : 11/04/2025 15:47
    task    : d
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    pair <ll, ll> a[n];
    for (auto &[x, y] : a) cin >> x >> y;
    sort(a, a+n);
    ll dp[n], ans = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) if (a[i].first > a[j].first && a[i].second > a[j].second) dp[i] += dp[j], dp[i] %= mod;
        ans += dp[i], dp[i] %= mod;
    }
    cout << ans << '\n';
}