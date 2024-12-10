#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;

    cin >> n;

    long long sum[n+1];
    sum[0] = 0;

    for (int i = 0; i < n; i++) {
        int a;

        cin >> a;

        sum[i+1] = sum[i] + a;
    }

    long long ans = sum[1], mi = sum[0];

    for (int i = 1; i <= n; i++) {
        ans = max({ans, sum[i] - mi});
        mi = min({mi, sum[i]});
    }

    cout << ans;
}
