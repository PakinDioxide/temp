#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k, c = 0;
    scanf("%d %d", &n, &k);
    int a[n], r = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] == 0 && c > 0) r++, c--;
        else if (a[i] >= k) c += a[i];
    }
    printf("%d\n", r);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
}