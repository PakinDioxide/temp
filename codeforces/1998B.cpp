#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 1; i < n; i++) printf("%d ", a[i]);
    printf("%d", a[0]);
    printf("\n");   
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
}