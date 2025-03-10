#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x, y;
    scanf("%d %d %d", &n, &x, &y);
    int a[n+1];
    for (int i = 1; i <= n; i++) {
        a[i] = -1;
        if ((i < y && i % 2 == y % 2) || (i % 2 == x % 2 && i > x)) a[i] = 1;
        if (i <= x && i >= y) a[i] = 1;
    }
    for (int i = 1; i <= n; i++) printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
}