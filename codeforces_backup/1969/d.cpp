#include <bits/stdc++.h>

using namespace std;

int main() {
    int q;
    scanf("%d", &q);
    while (q--) {
        int n, k;
        scanf("%d %d", &n, &k);
        int a[n], x;
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        for (int i = 0; i < n; i++) {scanf("%d", &x); a[i] -= x;}
        sort(a, a+n);
        int ans = 0, c = 0, cc = 0;
        for (int i = 0; i < n; i++) {
            a[i] *= -1;
            if (a[i] <= 0) c++;
            if (c > k) break;
            
        }
    }
}