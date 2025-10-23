/*
    author  : PakinDioxide
    created : 17/04/2025 14:29
    task    : 2014_Dec_G_1
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 20;

ll n, k;
tuple <ll, ll, ll> a[mxN];
ll dp[(1 << mxN)], H[(1 << mxN)], ok[(1 << mxN)], ans = LLONG_MIN;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("guard.in", "r", stdin);
    freopen("guard.out", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {auto &[h, w, s] = a[i]; cin >> h >> w >> s;}
    dp[0] = LLONG_MAX, H[0] = 0, ok[0] = 1;
    for (int i = 1; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) if (i & (1 << j)) {
            ll m = i ^ (1 << j);
            auto &[h, w, s] = a[j];
            if (w > dp[m] || ok[m] == 0) continue;
            H[i] = H[m] + h;
            ok[i] = 1;
            dp[i] = max(dp[i], min(dp[m]-w, s));
        }
        if (H[i] >= k) ans = max(ans, dp[i]);
    }
    if (ans == LLONG_MIN) cout << "Mark is too tall\n";
    else cout << ans << '\n';
}