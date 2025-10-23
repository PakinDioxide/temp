#include <bits/stdc++.h>

using namespace std;

long long MOD = 1e9+7;
const int MAX = 1e6;

long long fac[MAX], inv[MAX];

long long exp(long long a, long long b) {
    long long res = 1;
    a %= MOD;
    while (b > 0) {
        if (b % 2 == 1) res = res * a % MOD;
        a = a * a % MOD;
        b/=2;
    }
    return res;
}

void factorial() {
    fac[0] = 1;
    for (int i = 1; i <= MAX; i++) fac[i] = fac[i-1] * i % MOD;
}

void inverse() {
    inv[MAX] = exp(fac[MAX], MOD-2);
    for (int i = MAX; i >= 1; i--) inv[i-1] = inv[i] * i % MOD;
}

int main() {
    factorial();
    inverse();

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        long long a, b;
        cin >> a >> b;

        cout << fac[a] * inv[b] % MOD * inv[a-b] % MOD << '\n';
    }
}
