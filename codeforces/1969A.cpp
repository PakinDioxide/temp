#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    int a[n+1];
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int ok = 0;
    for (int i = 1; i <= n; i++) {
        if (i == a[a[i]]) {ok = 1; break;}
    }
    printf("%d\n", 3 - ok);
}

int main() {
    int q;
    scanf("%d", &q);
    while (q--) solve();
}