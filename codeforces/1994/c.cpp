#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, x, c = 0;
        scanf("%d %d", &n, &x);
        int a[n];
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        int dp[n];
        // int a[n+1];
        // for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        // int r = 0, rc = 0, rrc = 0, ridx = 0, p[n+1];
        // p[0] = 0;
        // queue <pair <int, int>> q;
        // for (int i = 1; i <= n; i++) {
        //     int g = 0;
        //     r = q.front().first, ridx = q.front().second;
        //     rc = p[ridx], rrc = p[n] - p[r];
        //     q.pop();
        //     if (i != 1) c += rrc - p[i-1];
        //     if (i != 1 && r - a[i-1] > x) {c += rc; continue;}
        //     if (i != 1) g = r - a[i-1];
        //     while (!q.empty()) q.pop();
        //     for (int j = max(i, ridx + 1); j <= n; j++) {
        //         g += a[j];
        //         p[j] = p[j-1];
        //         if (g > x) {
        //             q.emplace(g, j);
        //             g = 0;
        //         } else {
        //             c++;
        //             p[j]++;
        //         }
        //     }
        // }
        // printf("%d\n", c);
    }
}