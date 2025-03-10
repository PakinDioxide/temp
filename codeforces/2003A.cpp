#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    char s[n];
    scanf("%s", &s);
    int ok = s[0] != s[n-1];
    if (ok) printf("YES\n");
    else printf("NO\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
}