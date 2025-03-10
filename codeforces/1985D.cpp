#include <bits/stdc++.h>

using namespace std;

int32_t main() {
    int q;
    scanf("%d", &q);
    while (q--) {
        int n, m, a = INT_MAX, b = 0, c = INT_MAX, d = 0;
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            char s[m+1];
            scanf("%s", s+1);
            for (int j = 1; j <= m; j++) {
                if (s[j] == '#') a = min(i, a), b = max(i, b), c = min(j, c), d = max(j, d);
            }
        }
        printf("%d %d\n", (a+b)/2, (c+d)/2);
    }
}