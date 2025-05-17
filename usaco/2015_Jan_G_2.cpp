/*
    author  : PakinDioxide
    created : 02/05/2025 09:27
    task    : 2015_Jan_G_2
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll mxN = 20;

pair <ll, ll> dp[1 << mxN];
ll ok[1 << mxN], ans = LLONG_MAX, d[mxN];
vector <ll> a[mxN];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    // freopen("movie.in", "r", stdin);
    // freopen("movie.out", "w", stdout);
    ll n, L;
    cin >> n >> L;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> d[i] >> x;
        a[i].resize(x);
        for (auto &e : a[i]) cin >> e;
    }
    dp[0] = {0, 0};
    ok[0] = 1;
    for (int i = 1; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) if (i & (1 << j)) {
            if (!ok[i ^ (1 << j)]) continue;
            auto [k, T] = dp[i ^ (1 << j)];
            int it = upper_bound(a[j].begin(), a[j].end(), k) - a[j].begin() - 1;
            if (it == a[j].size() || it < 0 || a[j][it] < T) continue;
            if (dp[])
            if (dp[i] == L) ans = min(ans, (ll) __builtin_popcount(i));
            break;
        }
        bitset<4> y(i);
        cout << y << ' ' << dp[i] << '\n';
    }
    cout << (ans == LLONG_MAX ? -1 : ans) << '\n';
}