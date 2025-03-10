#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    int mx = 0, x;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if ((i - 0) % 2 == 0) mx = max(mx, x);
    }
    printf("%d\n", mx);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
}