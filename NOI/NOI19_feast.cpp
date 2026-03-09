#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 3e5+5;

int n, k;
ll a[mxN];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    auto solve = [&] (ll ld) {
        pair <ll, ll> dp[n+1][2];
        dp[1][0] = make_pair(0, 0);
        dp[1][1] = make_pair(a[1] - ld, 1);
        for (int i = 2; i <= n; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = max(make_pair(dp[i-1][0].first + a[i] - ld, dp[i-1][0].second + 1), make_pair(dp[i-1][1].first + a[i], dp[i-1][1].second));
        }
        return max(dp[n][0], dp[n][1]);
    };
    ll L = 0, R = 1e18, ans = 0;
    while (L <= R) {
        ll ld = L + (R-L)/2;
        pair <ll, ll> v = solve(ld);
        if (v.second >= k) ans = ld, L = ld+1;
        else R = ld-1;
    }
    cout << solve(ans).first + ans * k << '\n';
}