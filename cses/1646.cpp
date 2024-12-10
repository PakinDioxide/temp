#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    long long dp[n+1];
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {cin >> dp[i]; dp[i] += dp[i-1];}
    while (m--) {
        int a, b;
        cin >> a >> b;
        cout << dp[b] - dp[a-1] << '\n';
    }
}