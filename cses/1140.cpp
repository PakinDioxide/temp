/*
    author  : PakinDioxide
    created : 11/03/2025 19:56
    task    : 1140
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <tuple <ll, ll, ll>> a(n);
    int b[n+1];
    b[0] = 0;
    for (auto &[r, l, p] : a) cin >> l >> r >> p;
    a.emplace_back(0, 0, 0);
    sort(a.begin(), a.end());
    for (int i = 1; i <= n; i++) b[i] = -get<0>(a[i]);
    sort(b, b+n+1);
    ll dp[n+1];
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i-1];
        auto [r, l, p] = a[i];
        int idx = n - (upper_bound(b, b+n+1, -l) - b);
        dp[i] = max(dp[i], dp[idx] + p);
    }
    cout << dp[n] << '\n';
}