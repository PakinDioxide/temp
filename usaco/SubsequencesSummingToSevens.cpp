#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    int n;

    cin >> n;

    long long sum[n+1];

    sum[0] = 0;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        sum[i+1] = sum[i] + a;
    }

    for (int i = n; i > 0; i--) {
        for (int j = 0; j + i <= n; j++) {
            if ((sum[i+j]-sum[j])%7==0) {
                cout << i;
                return 0;
            }
        }
    }

    cout << 0;
}
