#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    long long MOD = 1e9+7;
    cin >> n >> x;
    vector <long long> a(n), c(x+1);

    for (int i = 0; i < n; i++) cin >> a[i];

    c[0] = 1;

    for (int i = 1; i <= x; i++) {
        for (auto j : a) {
            if (j <= i) c[i] = (c[i] + c[i-j]) % MOD;
        }
    }

    cout << c[x] % MOD;
}
