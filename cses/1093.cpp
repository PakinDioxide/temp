#include <bits/stdc++.h>

using namespace std;

long long dp[250*501+1], mod = 1e9+7;

long long poww(int x, int y) {
    if (y == 0) return 1;
    long long k = poww(x, y/2) % mod;
    return (k * k * (y % 2 == 0 ? 1 : x)) % mod;
}

int main() {
    int n;
    cin >> n;
    int sum = n*(n+1)/2;
    if (sum % 2 != 0) {cout << 0; return 0;}
    sum /= 2;
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = sum; j >= i; j--) dp[j] += dp[j-i], dp[j] %= mod; 
    }
    cout << (dp[sum] * poww(2, mod-2)) % mod;
}