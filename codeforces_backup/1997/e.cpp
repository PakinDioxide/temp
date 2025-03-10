#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    bool ok[n+1][n+1];
    for (int i = 1; i <= n; i++) {
        int x = 1, c = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] >= x) c++, ok[j][i] = 1;
            if (c == i) x++, c = 0;
        }
    }
    while (q--) {
        int i, x;
        scanf("%d %d", &i, &x);
        if (ok[i][x]) printf("YES\n");
        else printf("NO\n");
    }
}