#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    scanf("%d %d", &n, &m);
    char a[n][m];
    int cw[4], cb[4];
    for (int i = 0; i < 4; i++) cw[i] = cb[i] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &a[i][j]);
            if (i == 0) {
                if (a[i][j] == 'W') cw[0] = 1;
                else cb[0] = 1;
            }
            if (i == n-1) {
                if (a[i][j] == 'W') cw[1] = 1;
                else cb[1] = 1;
            }
            if (j == 0) {
                if (a[i][j] == 'W') cw[2] = 1;
                else cb[2] = 1;
            }
            if (j == m-1) {
                if (a[i][j] == 'W') cw[3] = 1;
                else cb[3] = 1;
            }
        }
    }
    if ((cw[0] && cw[1] && cw[2] && cw[3]) || (cb[0] && cb[1] && cb[2] && cb[3])) printf("YES\n");
    else printf("NO\n");
}

int main() {
    int q;
    scanf("%d", &q);
    while (q--) solve();
}