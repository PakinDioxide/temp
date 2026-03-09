#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll mod1 = 1e9+7, mod2 = 1e9+9;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m; cin >> n >> m;
    string a[n];
    for (auto &e : a) cin >> e;
    ll dp[n][m], dpp[n][m]; memset(dp, 0, sizeof(dp)), memset(dpp, 0, sizeof(dpp));
    dp[0][0] = 1, dpp[0][0] = 1;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        if (i > 0) dp[i][j] += dp[i-1][j], dp[i][j] %= mod1, dpp[i][j] += dpp[i-1][j], dpp[i][j] %= mod2;
        if (j > 0) dp[i][j] += dp[i][j-1], dp[i][j] %= mod1, dpp[i][j] += dpp[i][j-1], dpp[i][j] %= mod2;
        if (a[i][j] == '*') dp[i][j] = 0, dpp[i][j] = 0;
    }
    int fz = 0;
    for (auto &E : a) for (auto &e : E) fz += (e == '.');
    if (dp[n-1][m-1] == 0 && dpp[n-1][m-1] == 0) {
        cout << fz * (fz-1) / 2 << '\n';
        return 0;
    }
    ll dp2[n][m], dpp2[n][m]; memset(dp2, 0, sizeof(dp2)), memset(dpp2, 0, sizeof(dpp2));
    dp2[n-1][m-1] = 1, dpp2[n-1][m-1] = 1;
    for (int i = n-1; i >= 0; i--) for (int j = m-1; j >= 0; j--) {
        if (i < n-1) dp2[i][j] += dp2[i+1][j], dp2[i][j] %= mod1, dpp2[i][j] += dpp2[i+1][j], dpp2[i][j] %= mod2;
        if (j < m-1) dp2[i][j] += dp2[i][j+1], dp2[i][j] %= mod1, dpp2[i][j] += dpp2[i][j+1], dpp2[i][j] %= mod2;
        if (a[i][j] == '*') dp2[i][j] = 0, dpp2[i][j] = 0;
    }
    ll ans = 0, tt = fz;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (a[i][j] == '.') {
        if ((dp[i][j] * dp2[i][j]) % mod1 == dp[n-1][m-1] && (dpp[i][j] * dpp2[i][j]) % mod2 == dpp[n-1][m-1]) {
            ans += tt-1;
            tt--;
        }
    }
    unordered_map <ll, bool> mp, mpp;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) mp[(dp[i][j] * dp2[i][j]) % mod1] = 1, mpp[(dpp[i][j] * dpp2[i][j]) % mod2] = 1;
    ll ans2 = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (a[i][j] == '.' && ((dp[i][j] * dp2[i][j]) % mod1 != dp[n-1][m-1] || (dpp[i][j] * dpp2[i][j]) % mod2 != dpp[n-1][m-1]) && ((dp[i][j] * dp2[i][j]) % mod1 > 0 || (dpp[i][j] * dpp2[i][j]) % mod2 > 0) && mp[(dp[n-1][m-1] - (dp[i][j] * dp2[i][j]) % mod1 + mod1) % mod1] && mpp[(dpp[n-1][m-1] - (dpp[i][j] * dpp2[i][j]) % mod2 + mod2) % mod2]) ans2++;//, cout << i << ' ' << j << '\n';
    cout << ans + ans2/2 << '\n';
}

/*
if we add just ONE, we could do check for all point, then check if st->x * x->en == st->en? if yes = we can block just one point, else no
*/

