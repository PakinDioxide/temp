/*
    author  : PakinDioxide
    created : 20/03/2025 00:13
    task    : toi20_sculpture
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    pair <ll, ll> a[n];
    for (auto &[x, y] : a) cin >> x >> y;
    ll dp[2][n], cnt[n];
    for (int i = 0; i < n; i++) {dp[0][i] = a[i].first, cnt[i] = 1; if (i > 0) dp[0][i] = min(dp[0][i], dp[0][i-1]);}
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) dp[i&1][j] = INT_MAX;
        for (int j = 1; j < n; j++) {
            if (dp[!(i&1)][j-1] <= a[j].second) dp[i&1][j] = dp[!(i&1)][j-1] + a[j].first, cnt[j] = i+1;
            dp[i&1][j] = min(dp[i&1][j], dp[i&1][j-1]);
        }
    }
    ll dp2[2][n], cnt2[n];
    for (int i = n-1; i >= 0; i--) {dp2[0][i] = a[i].second, cnt2[i] = 1; if (i < n-1) dp2[0][i] = max(dp2[0][i], dp2[0][i+1]);}
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) dp2[i&1][j] = 0;
        for (int j = n-2; j >= 0; j--) {
            if (dp2[!(i&1)][j+1] >= a[j].first) dp2[i&1][j] = min(dp2[!(i&1)][j+1] - a[j].first, a[j].second), cnt2[j] = i+1;
            dp2[i&1][j] = max(dp2[i&1][j], dp2[i&1][j+1]);
        }
    }
    for (int i = n-2; i >= 0; i--) cnt2[i] = max(cnt2[i], cnt2[i+1]);
    int mx = 0;
    vector <int> ans;
    for (int i = 0; i < n-1; i++) {
        if (cnt[i] + cnt2[i+1] > mx) mx = cnt[i] + cnt2[i+1], ans.clear();
        if (cnt[i] + cnt2[i+1] == mx) ans.push_back(i+1);
    }
    cout << mx << '\n';
    for (auto &e : ans) cout << e << ' ';
    cout << '\n';
}