#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        vector <vector <int>> a(n+2, vector <int>(m+2));
        for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int k = max({a[i-1][j], a[i+1][j], a[i][j-1], a[i][j+1]});
                if (a[i][j] > k) a[i][j] = k;
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
    }
}