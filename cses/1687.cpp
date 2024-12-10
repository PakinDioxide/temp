#include <bits/stdc++.h>

using namespace std;

int n, q;

int up[20][200005];

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 2; i <= n; i++) scanf("%d", &up[0][i]);
    for (int i = 1; i < 20; i++) for (int j = 2; j <= n; j++) up[i][j] = up[i-1][up[i-1][j]];
    while (q--) {
        int x, y;
        scanf("%d %d", &x, &y);
        for (int i = 0; i < 20; i++) if (y & (1 << i)) x = up[i][x];
        printf("%d\n", x?:-1);
    }
}