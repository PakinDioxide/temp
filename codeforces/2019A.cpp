#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    int a[n], sa = 0, sb = 0, cnta = 0, cntb = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (i & 1) {
            cnta++;
            sa = max(a[i], sa);
        } else {
            cntb++;
            sb = max(a[i], sb);
        }
    }
    printf("%d\n", max(sa + cnta, sb + cntb));
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
}