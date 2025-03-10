#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a+n);
    int r = -1, c = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (r != a[i]) {
            ans += c/3;
            c = 0;
        }
        r = a[i];
        c++;
    }
    ans += c/3;
    printf("%d\n", ans);
}

int main() {
    int q;
    scanf("%d", &q);
    while (q--) solve();
}