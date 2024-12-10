#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int cnt = 0;
    if ((a > c && b > d) || (a == c && b > d) || (a > c && b == d)) cnt++;
    if ((a > d && b > c) || (a == d && b > c) || (a > d && b == c)) cnt++;
    if ((b > c && a > d) || (b == c && a > d) || (b > c && a == d)) cnt++;
    if ((b > d && a > c) || (b == d && a > c) || (b > d && a == c)) cnt++;
    printf("%d\n", cnt);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
}