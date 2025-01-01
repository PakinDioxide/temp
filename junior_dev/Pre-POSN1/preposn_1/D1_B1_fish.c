#include <stdio.h>

void solve() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + n/2 - 1; j++) {
            if (((j + i == (n-1)/2 || j - i == n/2 || (n + n/2 - 2) - j == i - 1) && i <= (n-1)/2) || (((i == j + n/2) || (i + j == n + n/2 - 1) || (n + n/2 - 2) - j == n - i - 2) && i >= n/2) || (j == n + n/2 - 2 && i != 0 && i != n-1)) printf("#");
            else if ((((j + i > (n-1)/2 && j - i < n/2) || ((n + n/2 - 2) - j < i - 1)) && i <= (n-1)/2) || ((((i < j + n/2) && (i + j < n + n/2 - 1)) || (n + n/2 - 2) - j < n - i - 2) && i >= n/2)) printf("=");
            else printf(".");
        }
        printf("\n");
    }
}

int main() {
    int q;
    scanf("%d", &q);
    while (q--) solve();
}