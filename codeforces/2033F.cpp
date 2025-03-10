#include <bits/stdc++.h>

using namespace std;

#define int long long

int mod = 1e9+7, fibo[400005];

int mult(int x, int y) {
    if (y == 1) return x;
    int k = mult(x, y/2);
    k = (2 * k) % mod;
    if (y % 2 == 1) k += x;
    return k % mod;
}

void solve() {
    int n, k;
    cin >> n >> k;
    if (k == 1) {
        cout << n % mod << '\n';
        return;
    }
    int i = 3;
    fibo[1] = fibo[2] = 1;
    while (1) {
        fibo[i] = (fibo[i-1] + fibo[i-2]) % k;
        if (fibo[i] == 0) break;
        i++;
    }
    cout << mult(n % mod, i) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}