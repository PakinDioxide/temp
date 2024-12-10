#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    int a[n+1], mx = 0, x;
    for (int i = 1; i <= n; i++) a[i] = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        mx = max(x, mx);
        a[x]++;
    }
    for (int i = n; i >= 1; i--) {
        if (a[i] == 0) continue;
        if (a[i] & 1) {printf("YES\n"); return;}
    }
    printf("NO\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
}