#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    int a[n+1], ans = 0, l = 0, r = 1;
    a[0] = 0;
    for (int i = 1; i <= n; i++) {cin >> a[i]; a[i] += a[i-1];}
    while (l < n && r <= n) {
        if (a[r] - a[l] == x) ans++;
        if (a[r] - a[l] >= x) l++;
        else r++;
    }
    cout << ans << '\n';
}