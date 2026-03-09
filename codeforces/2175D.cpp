#include <bits/stdc++.h>
#define ll long long
#define int ll

using namespace std;

pair <int, int> cmp(pair <int, int> x, pair <int, int> y) {
    if (x.first < y.first) return y;
    else if (x.first > y.first) return x;
    else {
        if (x.second < y.second) return x;
        else return y;
    }
}

void solve() {
    int n, K; cin >> n >> K;
    int a[n+1]; for (int i = 1; i <= n; i++) cin >> a[i];
    vector <pair <int, int>> v;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] <= mx) continue;
        v.emplace_back(a[i], i);
        mx = a[i];
        // cout << a[i] << ' ';
    }
    // cout << '\n';
    // cout << "DP : \n";
    // v.emplace_back(0, n+1);
    int sz = v.size(), ans = 0;
    // sz++;
    // int dp[sz+1][K+1]; memset(dp, 0, sizeof(dp));
    // for (int i = 1; i < sz; i++) {
    //     for (int j = i+1; j <= sz; j++) {
    //         for (int k = 0; k <= K; k++) {

    //         }
    //     }
    // }
    // int dp[sz+1][K+1]; memset(dp, 0, sizeof(dp));
    // for (int i = 1; i <= sz; i++) {
    //     auto [x, y] = v[i-1];
    //     for (int j = 0; j <= K; j++) {
    //         if (j > 0) dp[i][j] = max(dp[i][j], dp[i][j-1]);
    //         for (int k = 0; k <= x; k++) {
    //             if (j < k) break;
    //             dp[i][j] = max(dp[i][j], dp[i-1][j-k] + k * ((i < sz ? v[i].second : n+1) - y));
    //             ans = max(ans, dp[i-1][j-k] + k * (n+1 - y));
    //         }
    //         dp[i][j] = max(dp[i][j], dp[i-1][j]);
    //         cout << dp[i][j] << ' ';
    //         ans = max(ans, dp[i][j]);
    //     }
    //     cout << '\n';
    // }
    pair <int, int> dp[sz+1][K+1];
    for (int i = 0; i <= sz; i++) for (int j = 0; j <= K; j++) dp[i][j] = make_pair(0, 0);
    
    for (int i = 1; i <= sz; i++) {
        auto [x, y] = v[i-1];
        for (int j = 0; j <= K; j++) {
            if (j > 0) dp[i][j] = cmp(dp[i][j], dp[i][j-1]);
            dp[i][j] = cmp(dp[i][j], dp[i-1][j]);
            for (int k = 0; k <= x; k++) {
                if (j < k) break;
                dp[i][j] = cmp(dp[i][j], make_pair(dp[i-1][j-k].first + (k - dp[i-1][j-k].second) * (n+1 - y), k));
                ans = max(ans, dp[i][j].first);
            }
            // cout << dp[i][j].first << ' ';
            ans = max(ans, dp[i][j].first);
        }
        // cout << '\n';
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

/*
decomposed to at most 360 ns
*/