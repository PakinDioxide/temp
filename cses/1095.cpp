#include <bits/stdc++.h>

using namespace std;

long long MOD = 1e9+7;

long long exp(long long a, long long b) {
    long long res = 1;
    a %= MOD;
    while (b > 0) {
        if (b % 2) res = res * a % MOD;
        a = a * a % MOD;
        b/=2;
    }
    return res;
}

int main() {
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        long long a, b;
        cin >> a >> b;
        long long out = exp(a, b);
        cout << out << '\n';
    }
}
