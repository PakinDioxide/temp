#include <stdio.h>

// int n, a[1005][1005], ans = 0;

// void solve(int x, int y) {
//     if (x == n || ans) {ans = 1; return;}
//     for (int k = 1; k <= n; k++) {
//         // printf("%d %d %d\n", x, y, k);
//         int ok = 1;
//         for (int i = 1; x - i >= 0 && y - i >= 0; i++) if (a[x-i][y-i] == k) {ok = 0; break;}
//         if (!ok) continue;
//         for (int i = 1; x + i < n && y + i < n; i++) if (a[x+i][y+i] == k) {ok = 0; break;}
//         if (!ok) continue;
//         for (int i = 0; i < n; i++) if (a[i][y] == k || a[x][i] == k) {ok = 0; break;}
//         if (!ok) continue;
//         a[x][y] = k;
//         if (y + 1 < n) solve(x, y+1);
//         else solve(x+1, 0);
//         if (ans) return;
//         a[x][y] = 0;
//     }
// }

int main() {
    int n;
    scanf("%d", &n);
    if (n % 2 == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) printf("%d ", (i+j)%n + 1);
            printf("\n");
        }
    } else {
        if (n == 2) {printf("-1"); return 0;}
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (i == n-1) k = 2;
            else if (i % 2 == 0) k++, k = k > n ? k - n : k;
            else k += 2, k = k > n ? k - n : k;
            int x = k;
            for (int j = 0; j < n; j++) {
                printf("%d ", x);
                x = x%n + 1;
            }
            printf("\n");
        }
        // int a[n+1][n+1];
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) a[i][j] = (i+j)%n + 1;
        // }
        // for (int i = 0; i < n; i++) {
        //     // for (int j = 0; j < n; j++) printf("%d %d\n", i, j % 2 == 0 ? n - j/2 - 1 : j/2);
        //     // for (int j = 0; j < n; j++) printf("%d ", a[i][j % 2 == 0 ? j+1 : j-1]);
        //     for (int j = 0; j < n; j++) printf("%d ", a[i >= n/2 ? (i == n/2 ? n-1 : i-1) : i][j]);
        //     // for (int j = 0; j < n; j++) printf("%d ", a[i][j]);
        //     printf("\n");
        // }
    }
}