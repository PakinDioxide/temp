#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        char x[n][m+1], y[n][m+1];
        int a[n][m], ok = 1;
        for (int i = 0; i < n; i++) scanf("%s", &x[i]);
        for (int i = 0; i < n; i++) {scanf("%s", &y[i]); for (int j = 0; j < m; j++) a[i][j] = (y[i][j] - x[i][j] + 3) % 3;}
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == n-1 || j == m-1) {
                    if (a[i][j] % 3 != 0) {ok = 0; break;}
                } else if (a[i][j] == 1) {
                    a[i+1][j+1] += 2;
                    a[i+1][j+1] %= 3;
                    a[i+1][j]++;
                    a[i+1][j] %= 3;
                    a[i][j+1]++;
                    a[i][j+1] %= 3;
                    a[i][j] = 0;
                } else if (a[i][j] == 2) {
                    a[i+1][j+1]++;
                    a[i+1][j+1] %= 3;
                    a[i+1][j] += 2;
                    a[i+1][j] %= 3;
                    a[i][j+1] += 2;
                    a[i][j+1] %= 3;
                    a[i][j] = 0;
                }
                // printf("%d ", a[i][j]);
            }
            // printf("\n");
            if (!ok) break;
        }
        if (ok) printf("Yes\n");
        else printf("No\n");
    }
}