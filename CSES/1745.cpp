#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    int a[n+1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    set <int> dp[n+1];
    dp[1].insert(0), dp[1].insert(a[1]);
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1];
        for (int e : dp[i-1]) dp[i].insert(e+a[i]);
    }
    cout << dp[n].size()-1 << '\n';
    for (int e : dp[n]) if (e > 0) cout << e << ' ';
    cout << '\n';
}