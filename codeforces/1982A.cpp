#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        if (a == b || (a > b && c > d) || (a < b && c < d)) printf("Yes\n");
        else printf("No\n");
    }
}