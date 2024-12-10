#include <bits/stdc++.h>

using namespace std;

int row[1005][1005], col[1005][1005], lr[2005][1005], ans[1005][1005];

int main() {
    int n, ok = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ok = 0;
            for (int x = 0; x < n; x++) {
                if (!row[i][x] && !col[j][x] && !lr[n-j-1+i][x]) {ans[i][j] = x, row[i][x] = col[j][x] = lr[n-j-1+i][x] = ok = 1; break;}
            }
            if (!ok) break;
        }
        if (!ok) break;
    }
    if (ok) printf("-1");
    else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) printf("%d ", ans[i][j] + 1);
            printf("\n");
        }
    }
}