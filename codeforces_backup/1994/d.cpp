#include <bits/stdc++.h>

using namespace std;

int par[2005];

int fi(int x) {
    if (x != par[x]) par[x] = fi(par[x]);
    return x;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int a[n], ok = 1;
        for (int i = 0; i < n; i++) scanf("%d", &a[i]), par[i] = i;
        pair <int, int> p[n-1];
        for (int o = n-1; o > 0 && ok; o--) {
            ok = 0;
            for (int i = 0; i < n; i++) {
                for (int j = i+1; j < n; j++) {
                    if (abs(a[i] - a[j]) % o == 0 && fi(i) != fi(j)) {par[fi(i)] = par[fi(j)]; p[o-1] = {i+1, j+1}; ok = 1; break;}
                }
                if (ok) break;
            }
        }
        if (!ok) printf("NO\n");
        else {
            printf("YES\n");
            for (auto [u, v] : p) printf("%d %d\n", u, v);
        }
    }
}