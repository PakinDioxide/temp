#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        printf("%d\n", max({a, b ,c}) - min({a, b, c}));
    }
}