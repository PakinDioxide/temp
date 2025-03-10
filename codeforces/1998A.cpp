#include <bits/stdc++.h>

using namespace std;

void solve() {
    int x, y, k, kk;
    scanf("%d %d %d", &x, &y, &k);
    for (int i = 2; i <= k; i+=2) printf("%d %d\n%d %d\n", x-i, y, x+i, y);
    if (k & 1) printf("%d %d\n", x, y);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
}