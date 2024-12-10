#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    long long MOD = 1e9+7;
    cin >> n;
    vector <long long> w(n+1);
    w[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            if (j <= i) w[i] = (w[i] + w[i-j]) % MOD;
            else break;
        }
    }

    cout << w[n];
}
