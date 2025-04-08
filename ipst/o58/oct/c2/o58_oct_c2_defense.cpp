/*
    author  : PakinDioxide
    created : 29/03/2025 21:05
    task    : o58_oct_c2_defense
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n >> k;
    ll a[n+1], ans = LLONG_MAX;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < min(n, k); i++) {
        ll dp[n+1];
        dp[0] = 0;
        dp[i] = a[i];
        deque <pair <ll, int>> dq;
        dq.emplace_back(a[i], 1);
        for (int j = i+1; j <= n; j++) {
            while (!dq.empty() && dq.front().second <= j-k) dq.pop_front();
            dp[j] = dq.front().first + a[j];
            while (!dq.empty() && dq.back().first >= dp[j]) dq.pop_back();
            dq.emplace_back(dp[j], j);
        }
        ll mn = LLONG_MAX;
        for (int j = n; j >= max(i+1, n-k+2); j--) {
            mn = min(mn, a[j]);
            ans = min(ans, mn + dp[j-1]);
        }
    }
    cout << ans << '\n';
}