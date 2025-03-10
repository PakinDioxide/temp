#include <bits/stdc++.h>

using namespace std;

int main() {
    int q;
    scanf("%d", &q);
    while (q--) {
        int x;
        scanf("%d", &x);
        int ans = 1;
        for (int i = 2; i < x; i++) {
            if (x % i == 0) {ans = i; break;}
        }
        printf("%d\n", x-ans);
    }
}