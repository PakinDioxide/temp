#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k = 0;
    scanf("%d %d", &n, &k);
    int o = k/2 + ((n-k+1)%2)*(k%2); // n-k+1 : n
    if (o % 2 == 0) printf("YES\n");
    else printf("No\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
}