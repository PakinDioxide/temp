#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    int a[n], mx = -1e9, mi = 1e9, mid = 1e9;
    vector <int> k;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]), mx = max(mx, a[i]), mi = min(mi, a[i]);
    while ((mx != 0 || mi != 0) && k.size() < 41) {
        mid = (mx + mi)/2;
        // printf("MX : %d %d %d\n", mx, mi, mid);
        mx = -1e9, mi = 1e9;
        k.push_back(mid);
        for (int i = 0; i < n; i++) a[i] = abs(a[i] - mid), mx = max(mx, a[i]), mi = min(mi, a[i]);
    }
    if (k.size() <= 40) {
        printf("%d\n", k.size());
        for (int i : k) printf("%d ", i);
    } else printf("-1");
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
}