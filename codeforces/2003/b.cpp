#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    int a[n], ans = 0;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a+n);
    printf("%d\n", a[((n)/2)]);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
}