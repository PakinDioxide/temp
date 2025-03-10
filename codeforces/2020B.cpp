#include <bits/stdc++.h>

using namespace std;

#define int long double

void solve() {
    int n;
    scanf("%Lf", &n);
    int ans = ceil(((1.0 + sqrt(4*n+1)))*((1.0 + sqrt(4*n+1)))/4)-1;
    if (ans - floor(sqrt(ans)) > n) ans--;
    while (ans - floor(sqrt(ans)) < n) ans++;
    printf("%.0Lf\n", ans);
}

int32_t main() {
    int t;
    scanf("%Lf", &t);
    while (t--) solve();
}