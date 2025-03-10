#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, k, cnt = 0;
    scanf("%d %d %d", &n, &m, &k);
    printf("%d\n", (n >= k ? k : n%k)*((m >= k ? k : m%k)));
}

int32_t main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
}