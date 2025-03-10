#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);
        int l = 0, r = 0, a[n+1][m+1];
        vector <vector <int>> c(n+1, vector <int>(m+1));
        for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
        char b[n+1][m+1];
        for (int i = 1; i <= n; i++) {
            scanf("%s", &b[i]);
            for (int j = 1; j <= m; j++) {
                c[i][j] = c[i-1][j] + c[i][j-1] - c[i-1][j-1];
                if (b[i][j-1] == '0') l += a[i][j];
                else r += a[i][j], c[i][j]++;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                printf("%d ", c[i][j]);
            }
            printf("\n");
        }
        int diff = abs(l - r), kk[4], k2 = k*k;
        kk[0] = kk[1] = kk[2] = kk[3] = 0;
        for (int i = 1; i <= n-k+1; i++) {
            for (int j = 1; j <= m-k+1; j++) {
                int rr = c[i+k-1][j+k-1] - c[i-1][j+k-1] - c[i+k-1][j-1] + c[i-1][j-1];
                int ll = k2 - rr;
                printf("%d %d\n", ll, rr);
                if (ll % 2 == 1) kk[1] = 1;
                else if (ll % 2 == 0 && ll != 0) kk[0] = 1;
                if (rr % 2 == 1) kk[3] = 1;
                else if (rr % 2 == 0 && rr != 0) kk[2] = 1;
            }
        }
        if (kk[1] && kk[3]) {printf("Yes\n"); continue;}
        else if (kk[0] && kk[2] && diff % 2 == 0) {printf("Yes\n"); continue;}
        else if ((kk[0] && kk[3]) || (kk[1] && kk[2])) {printf("Yes\n"); continue;}
        else printf("No\n");
    }
}