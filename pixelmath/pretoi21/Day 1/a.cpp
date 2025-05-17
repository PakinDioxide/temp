#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 300;

ll n, k, t;
tuple <ll, ll, ll> a[mxN];
set <ll> dp[mxN][50];
set <ll> ans;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k >> t;
    t--;
    a[0] = {0, 0, 0};
    for (int i = 1; i <= n; i++) { auto &[x, y, z] = a[i]; cin >> x >> y >> z; }
    sort(a+1, a+n+1);
    dp[0][0].emplace(0);
    for (int i = 1; i <= n; i++) {
        auto &[x, y, z] = a[i];
        for (int j = 0; j < i; j++) {
            if (get<0>(a[j]) == x) break;
            if (get<1>(a[j]) > y) continue;
            if (get<2>(a[j]) == z) for (int ii = 0; ii+1 <= t; ii++) for (auto &e : dp[j][ii]) dp[i][ii+1].emplace(e + y);
            else for (int ii = 0; ii <= t; ii++) for (auto &e : dp[j][ii]) dp[i][0].emplace(e + y);
        }
        for (int j = 0; j <= t; j++) while ((int)dp[i][j].size() > k) dp[i][j].erase(dp[i][j].begin());
        for (int j = 0; j <= t; j++) for (auto &e : dp[i][j]) ans.emplace(e);
        while ((int)ans.size() > k) ans.erase(ans.begin());
    }
    if (ans.size() == k) cout << *ans.begin() << '\n';
    else cout << 0 << '\n';
}