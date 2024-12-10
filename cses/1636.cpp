#include <bits/stdc++.h>
 
using namespace std;
 
int dp[1000005], mod = 1e9+7;
 
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n >> k;
    dp[0] = 1;
    while (n--) {
        int x;
        cin >> x;
        for (int i = x; i <= k; i++) dp[i] += dp[i-x], dp[i] %= mod;
    }
    cout << dp[k];
}