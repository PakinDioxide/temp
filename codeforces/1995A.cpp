#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k, c = 0;
    scanf("%d %d", &n, &k);
    while (k > 0 && n > 0) {
        c++;
        k -= n;
        n -= (c % 2);
    }
    printf("%d\n", c);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
}