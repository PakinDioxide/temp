/*
    author  : PakinDioxide
    created : 10/04/2025 21:32
    task    : 2020_Jan_B_3
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    // freopen("race.in", "r", stdin);
    // freopen("race.out", "w", stdout);
    ll k, n;
    cin >> k >> n;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        ll dp[k+1], ans = LLONG_MAX;
        dp[0] = 0;
        for (int i = 1; i <= k; i++) {
            dp[i] = dp[i-1] + i;
            cout << "I " << i << '\n';
            cout << dp[i] << ' ' << max(0LL, dp[i-1] - dp[x-1]) + dp[i] << '\n';
            if (max(0LL, dp[i-1] - dp[x-1]) + dp[i] < k+x) {
                ll y = k - (max(0LL, dp[i-1] - dp[x]) + dp[i]);
                cout << " Y " << y << '\n';
                ans = min(ans, max(0LL, i - x) + i + y/i + min(1LL, y%i));
            } else break;
        }
        cout << ans << '\n';
    }
}

/*
1
3
6
8
10

*/