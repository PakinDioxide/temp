#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, s, m;
    scanf("%d %d %d", &n, &s, &m);
    int p[n+1];
    for (int i = 0; i <= n; i++) p[i] = 0;
    for (int i = 0; i < n; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        p[l] = (r - l);
    }
    int cnt = 0, mx = 0, ss = 0;
    for (int i = 1; i <= m; i++) {
        if (ss > 0) ss--;
        ss += p[i];
        if (ss == 0) cnt++;
        mx = max(mx, cnt);
    }
    if (mx >= s) printf("YES\n");
    else printf("NO\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
}