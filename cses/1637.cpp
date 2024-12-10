#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int dp[n+1];
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int k = 1;
        dp[i] = INT_MAX;
        while (k <= n) {
            if ((i/k) % 10 != 0) dp[i] = min(dp[i], dp[i - (i/k)%10] + 1);
            k *= 10;
        }
    }
    cout << dp[n];
}