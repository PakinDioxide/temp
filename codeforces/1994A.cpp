#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        int a[n][m];
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
        if (n == 1 && m == 1) {printf("-1\n"); continue;}
        int b[n][m];
        for (int i = 0; i < n; i++) for (int j = 0; j < m/2; j++) swap(a[i][j], a[i][m-j-1]);
        if (m & 1) for (int i = 0; i < n; i++) swap(a[i][(m-1)/2], a[i][m-1]);
        for (int j = 0; j < m; j++) for (int i = 0; i < n/2; i++) swap(a[i][j], a[n-i-1][j]);
        if (n & 1) for (int j = 0; j < m; j++) swap(a[(n-1)/2][j], a[n-1][j]);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) printf("%d ", a[i][j]);
            printf("\n");
        }
    }
}