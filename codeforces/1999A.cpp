#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a;
    scanf("%d", &a);
    printf("%d\n", a/10+a%10);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
}