#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    int b[n], a[n], ok = 1;
    for (int i = 1; i < n; i++) scanf("%d", &b[i]);
    a[0] = b[1], a[n-1] = b[n-1];
    // for (int i = 1; i < n; i++) a[i] = (!a[i-1]) | b[i];
    for (int i = 1; i < n - 1; i++) a[i] = b[i] | b[i+1];
    a[n-1] = b[n-1];
    for (int i = 1; i < n; i++) if (b[i] != (a[i-1] & a[i])) {ok = 0; break;}
    if (!ok) {printf("-1\n"); return;}
    for (int i : a) printf("%d ", i);
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
}