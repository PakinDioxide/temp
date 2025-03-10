#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    int a[n], mx = 0;
    map <int, int> c;
    for (int i = 0; i < n; i++) {scanf("%d", &a[i]); c[a[i]]++; mx = max(mx, c[a[i]]);}
    if (mx >= k) printf("%d\n", k-1);
    else printf("%d\n", n);
}

int main() {
    int q;
    scanf("%d", &q);
    while (q--) solve();
}