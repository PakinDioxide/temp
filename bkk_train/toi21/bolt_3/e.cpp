/*
    author  : PakinDioxide
    created : 01/05/2025 13:58
    task    : e
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 305;
const ll mod = 1e7+9;

ll n, m, x, a[mxN][mxN], dp[mxN][mxN], dp2[mxN][mxN];
map <ll, ll> mp[2][mxN];

int main() {
    // ios::sync_with_stdio(0), cin.tie(0);
    // cin >> n >> m >> x;
    scanf("%lld %lld %lld", &n, &m, &x);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) scanf("%lld", &a[i][j]);
    for (int i = n; i > 0; i--) for (int j = m; j > 0; j--) {
        if (i == n && j == m) {dp2[i][j] = 1; continue;}
        dp2[i][j] = LLONG_MAX;
        if (i < n) dp2[i][j] = min(dp2[i][j], min((ll) INT_MAX, dp2[i+1][j] * a[i+1][j]));
        if (j < m) dp2[i][j] = min(dp2[i][j], min((ll) INT_MAX, dp2[i][j+1] * a[i][j+1]));
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) cout << dp2[i][j] << ' ';
    //     cout << '\n';
    // }
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        if (i == 1 && j == 1) {if (a[i][j] < x) mp[i&1][j][a[i][j]] = 1; dp[i][j] = 1; continue;}
        mp[i&1][j].clear();
        if (i > 1) for (auto &e : mp[!(i&1)][j]) {if (e.first * a[i][j] <= x/dp2[i][j]) mp[i&1][j][e.first * a[i][j]] += e.second, mp[i&1][j][e.first * a[i][j]] %= mod; else break;}
        if (j > 1) for (auto &e : mp[i&1][j-1]) {if (e.first * a[i][j] <= x/dp2[i][j]) mp[i&1][j][e.first * a[i][j]] += e.second, mp[i&1][j][e.first * a[i][j]] %= mod; else break;}
        if (i > 1) dp[i][j] += dp[i-1][j], dp[i][j] %= mod;
        if (j > 1) dp[i][j] += dp[i][j-1], dp[i][j] %= mod;
    }
    ll ans = dp[n][m];
    for (auto &e : mp[n&1][m]) if (e.first < x) ans -= e.second, ans += mod, ans %= mod;
    printf("%lld\n", ans);
}

/*
ways = all - cant
*/