#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    int a[n], b[n], ok = 0;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);
    int la = 0, ra = n-1, lb = 0, rb = n-1;
    for (int i = 0; i < n-1; i++) {
        if (a[la] != b[lb] && a[la] != b[rb]) {ok = 1; break;}
        else if (a[ra] != b[lb] && a[ra] != b[rb]) {ok = 1; break;}
        if (a[la] == b[lb]) la++, lb++;
        else if (a[la] == b[rb]) la++, rb--;
    }
    if (ok) printf("Alice\n");
    else printf("Bob\n");
}

int32_t main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
}