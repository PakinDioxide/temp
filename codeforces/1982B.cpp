#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int a, b, k;
        scanf("%d %d %d", &a, &b, &k);
        while (k > 0) {
            int x = ((a+b)/b)*b;
            if (k < x - a) {a += k; break;}
            k -= (x - a);
            a = x;
            while (a % b == 0) a /= b;
            if (a == 1) {k %= (b - 1); a += k; break;}
        }
        printf("%d\n", a);
    }
}