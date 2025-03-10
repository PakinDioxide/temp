#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b;
    scanf("%d %d", &a, &b);
    int ok = 0;
    if (a % 2 == 1 || (b % 2 == 1 && a == 0)) printf("NO\n");
    else printf("YES\n");
} 

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
}