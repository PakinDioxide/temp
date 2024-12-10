#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;

    cin >> n;

    pair <int, int> a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort (a, a + n);

    long long ans = 0, cur = 0;

    for (int i = 0; i < n; i++) {
        cur += a[i].first;

        ans += a[i].second - cur;
    }

    cout << ans;
}
