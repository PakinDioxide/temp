/*
    author  : PakinDioxide
    created : 02/04/2025 22:27
    task    : toi17_sequel
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n, q;
    cin >> n >> q;
    ll x = sqrt(n), a[n+1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    ll dp[x+1][n+1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = a[j];
            if (j >= i) dp[i][j] += dp[i][j-i];
        }
    }
    while (q--) {
        ll l, m, r;
        cin >> l >> m >> r;
        if (r % m > l % m) r = r - r % m + l % m;
        else if (r % m < l % m) r = r - r % m - m + l % m;
        if (m > x) {
            ll ans = 0;
            while (l <= r) ans += a[l], l += m;
            cout << ans << ' ';
        } else {
            cout << dp[m][r] - dp[m][max(0LL, l-m)] << ' ';
        }
    }
    cout << '\n';
}

/*
we should do sqrt decomposition

let x = sqrt(n);

case 1 : M > x
    we just loop in the range
case 2 : R <= x
    we do prefix sum
    l mod m should equal r mod m

total : O(n sqrt(n))
*/