#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, ca, cb, cc, cd, cq;
    ca = cb = cc = cd = cq = 0;
    scanf("%d", &n);
    char s[4*n];
    scanf("%s", &s);
    for (char i : s) {
        if (i == 'A') ca++;
        else if (i == 'B') cb++;
        else if (i == 'C') cc++;
        else if (i == 'D') cd++;
    }
    printf("%d\n", min(ca, n) + min(cb, n) + min(cc, n) + min(cd, n));
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
}