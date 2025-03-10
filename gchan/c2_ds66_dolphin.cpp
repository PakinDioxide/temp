#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main() {
    int n;
    cin >> n;
    int a[n];
    a[0] = 2*n+n-2;
    a[n-1] = n*n-1+(n%2);
    for (int i = 1; i < n-1; i++) {
        if (i % 2 == 0) {
            a[i] = 2*(n-i+1)+2*(n-i+1-4)+1 + a[i-1];
        } else {
            a[i] = a[i-1] + 1;
        }
        a[i] %= 10;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) ans += a[i] % 10;
    cout << ans << '\n';
}