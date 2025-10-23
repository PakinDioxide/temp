#include <bits/stdc++.h>

using namespace std;

int x[2005][2005], y[2005][2005], MOD = 1e6+3;
char a[2000][2000];

int main() {
    int n, m, r, ans = 0;
    scanf("%d %d %d", &n, &m, &r);
    for (int i = 0; i < n; i++) scanf("%s", a[i]);
    for (int i = 1; i < 2000; i++) for (int j = 1; j < 2000; j++) {
        x[i][j] = x[i-1][j-1];
        y[i][j] = y[i-1][j+1];
        if (i >= 1000 && i < 1000 + n && j >= 1000 && j < 1000 + m && a[i-1000][j-1000] == '#') x[i][j]++, y[i][j]++;
    }
    int ncr[n*m+10][r+1];
    ncr[0][0] = 1;
    for (int i = 1; i <= n*m; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) ncr[i][j] = 1;
            else ncr[i][j] = (ncr[i-1][j-1] + ncr[i-1][j]) % MOD;
            if (j == r) break;
        }
    }
    for (int k = 1; k <= n+m; k++) {
        for (int i = 1000; i < 1000 + n; i++) for (int j = 1000; j < 1000 + m; j++) {
            int cnt = (x[i][j+k] - x[i-k-1][j-1]) + (x[i+k][j] - x[i-1][j-k-1]) + (y[i-1][j-k+1] - y[i-k][j]) + (y[i+k-1][j+1] - y[i][j+k]);
            if (cnt < r) continue;
            ans += ncr[cnt][r];
            ans %= MOD;
        }
    }
    printf("%d", ans);
}