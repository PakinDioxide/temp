#include <bits/stdc++.h>

using namespace std;

double n, a[30][30], dp[1 << 21], vi[1 << 21];

double solve(int i, int vis) {
    if (i == n) return 1;
    if (vi[vis]) return dp[vis];
    vi[vis] = 1;
    double mx = 0;
    for (int j = 0; j < n; j++) {
        if (vis & (1 << j)) continue;
        mx = max(mx, solve(i+1, vis | (1 << j)) * a[i][j]);
    }
    return dp[vis] = mx;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {cin >> a[i][j]; a[i][j] /= 100.0;}
    printf("%.12lf", solve(0, 0)*100.0);
}