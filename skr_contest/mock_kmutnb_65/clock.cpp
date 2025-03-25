/*
    author  : PakinDioxide
    created : 22/03/2025 20:55
    task    : clock
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    int idx = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        int h, m;
        scanf("%d:%d", &h, &m);
        double ang = abs(30*h - 6*m);
        int mx = max(floor(ang), floor(360-ang));
        if (mx > ans) ans = mx, idx = i;
    }
    printf("%d %d\n", idx, ans);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
}