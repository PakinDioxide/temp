/*
    author  : PakinDioxide
    created : 01/05/2025 13:05
    task    : a
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector <ll> dp(1000001);

void solve() {
    int n;
    cin >> n;
    cout << dp[n] << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    dp[1] = 0;
    for (int i = 2; i <= 1000000; i++) {
        dp[i] = dp[i-1] + 1;
        if (i % 2 == 0) dp[i] = min(dp[i], dp[i/2] + 1);
        if (i % 3 == 0) dp[i] = min(dp[i], dp[i/3] + 1);
    }
    int t;
    cin >> t;
    while (t--) solve();
}