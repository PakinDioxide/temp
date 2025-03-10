#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    n--;
    int x[n+1], a[n+1];
    for (int i = 0; i < n; i++) scanf("%d", &x[i]);
    a[0] = x[0]+1;
    x[n] = 0;
    printf("%d ", a[0]);
    for (int i = 0; i < n; i++) {
        a[i+1] = x[i];
        while (a[i+1] <= x[i+1]) a[i+1] += a[i];
        printf("%d ", a[i+1]);
    }
    printf("\n");
}

int main() {
    int q;
    scanf("%d", &q);
    while (q--) solve();
}